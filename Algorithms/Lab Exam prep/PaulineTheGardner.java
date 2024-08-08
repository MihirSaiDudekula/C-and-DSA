import java.util.*;

class Node
{
	String name;
	List<Edge> neighbours;

	public Node(String name)
	{
		this.name = name;
		this.neighbours = new ArrayList<>();
	}

	public void addEdge(Node n,int weight)
	{
		this.neighbours.add(new Edge(this,n,weight));
	}
}

class Edge
{
	Node from;
	Node to;
	int weight;

	public Edge(Node from,Node to,int weight)
	{
		this.from = from;
		this.to = to;
		this.weight = weight;
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
		graph.add(n);
	}

	public void createEdge(Node from,Node to,int weight)
	{
		from.addEdge(to,weight);
		to.addEdge(from,weight); //if undirected
	}

	List<Edge> mst = new ArrayList<>();
	PriorityQueue<Edge> minheap = new PriorityQueue<>(Comparator.comparingInt(e->e.weight));
	Set<Node> visited = new HashSet<>();

	public void visit(Node n,Set<Node> v,PriorityQueue<Edge> pq)
	{
		if(!v.contains(n))
		{
			v.add(n);
		}

		for(Edge e:n.neighbours)
		{
			if(!v.contains(e.to))
			{
				pq.offer(e);
			}
		}
	}

	public List<Edge> Prims(Node start)
	{
		visit(start,visited,minheap);

		while(!minheap.isEmpty())
		{
			Edge e = minheap.poll();
			Node goesto = e.to;
			Node comesfrm = e.from;

			if(visited.contains(comesfrm) && visited.contains(goesto))
			{
				continue;
			}

			mst.add(e);

			// Edge next = visited.contains(goesto)?comesfrm:goesto;

			visit(goesto,visited,minheap);
		}

		return mst;
	}

	public static void main(String args[])
	{
		Graph g = new Graph();

		Node nodeF = new Node("F");
		Node nodeA = new Node("A");
		Node nodeB = new Node("B");
		Node nodeC = new Node("C");
		Node nodeD = new Node("D");
		Node nodeE = new Node("E");

		g.addNode(nodeF);
		g.addNode(nodeA);
		g.addNode(nodeB);
		g.addNode(nodeC);
		g.addNode(nodeD);
		g.addNode(nodeE);

		g.createEdge(nodeF,nodeD,7);
		g.createEdge(nodeF,nodeE,8);
		g.createEdge(nodeD,nodeE,3);
		g.createEdge(nodeE,nodeA,4);
		g.createEdge(nodeD,nodeA,6);
		g.createEdge(nodeA,nodeC,2);
		g.createEdge(nodeB,nodeC,2);
		g.createEdge(nodeA,nodeB,5);

		List<Edge> ans = g.Prims(nodeF);

		int len = 0;
		for(Edge e:ans) 
		{
			System.out.println(e.from.name +"->"+ e.to.name+" :weight "+e.weight);
			len+=e.weight;
		}

		System.out.println("Total length: "+len);

	}
}