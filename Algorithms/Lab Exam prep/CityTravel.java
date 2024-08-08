import java.util.*;

class Node
{
	String city;
	List<Edge> neighbours;
	int distFromSrc;

	public Node(String name)
	{
		this.city=name;
		this.neighbours = new ArrayList<>();
		this.distFromSrc = Integer.MAX_VALUE;
	}

	public void addEdge(Node to,int weight)
	{
		this.neighbours.add(new Edge(this,to,weight));
	}
}

class Edge
{
	Node from;
	Node to;
	int weight;

	public Edge(Node from,Node to,int weight)
	{
		this.from=from;
		this.to=to;
		this.weight=weight;
	}
}

class Graph
{
    List<Node> graph;

    public Graph()
    {
    	this.graph = new ArrayList<>();
    }

    public void addNode(Node n)
    {
    	this.graph.add(n);
    }

    public void createEdge(Node from,Node to,int weight)
    {
    	from.addEdge(to,weight);
    	to.addEdge(from,weight);
    }

    PriorityQueue<Node> minheap = new PriorityQueue<>(Comparator.comparingInt(n -> n.distFromSrc));
    
    public void ShortPath(Node n, PriorityQueue<Node> pq) {
        for (Edge e : n.neighbours) {
            Node neighbor = e.to;
            if (n.distFromSrc + e.weight < neighbor.distFromSrc) 
            {
                neighbor.distFromSrc = n.distFromSrc + e.weight;
                pq.offer(neighbor);
            }
        }
    }

    public List<Node> Dijikstra(Node start)
    {
    	start.distFromSrc = 0;
    	minheap.offer(start);
    	while(!minheap.isEmpty())
    	{
    		Node x = minheap.poll();
    		ShortPath(x,minheap);
    	}
    	return graph;
    }

    public static void main(String[] args) {
            Graph g = new Graph();

            Node SF = new Node("San Francisco");
            Node LA = new Node("Los Angeles");
            Node DAL = new Node("Dallas");
            Node DNV = new Node("Denver");
            Node CHG = new Node("Chicago");
            Node NY = new Node("New York");
            Node BST = new Node("Boston");

            g.addNode(SF);
            g.addNode(LA);
            g.addNode(DAL);
            g.addNode(DNV);
            g.addNode(CHG);
            g.addNode(NY);
            g.addNode(BST);

            g.createEdge(SF, CHG, 5);
            g.createEdge(LA, CHG, 7);
            g.createEdge(LA, DAL, 5);
            g.createEdge(DAL, DNV, 4);
            g.createEdge(SF, DNV, 4);
            g.createEdge(SF, LA, 3);
            g.createEdge(BST, CHG, 3);
            g.createEdge(DAL, CHG, 5);
            g.createEdge(DNV, CHG, 6);
            g.createEdge(CHG, NY, 4);
            g.createEdge(NY, DAL, 6);
            g.createEdge(BST, NY, 2);

            List<Node> res = g.Dijikstra(SF);

            System.out.println("Distance from SF to each node:");
            for (Node n : res) {
                System.out.println("SF -> " + n.city + ": " + n.distFromSrc);
            }
        }

}