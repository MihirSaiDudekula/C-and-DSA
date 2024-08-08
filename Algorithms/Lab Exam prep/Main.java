import java.util.*;

class Node
{
	int val;
	List<Node> nbs; //list of neighbours 
	
	public Node(int val)
	{
		this.val=val;
		this.nbs = new ArrayList<>();
	}
	
	public void addNbs(Node nb)
	{
		this.nbs.add(nb);
	}
}

class Graph
{
	List<Node> nodes;
	
	public Graph()
	{
		this.nodes = new ArrayList<>();
	}
	
	public void addNode(Node n)
	{
		nodes.add(n);
	}
}
class DFS
{	
	public static void dfs(Node start)
	{
		Stack<Node> q = new Stack<>();
		Set<Node> visit = new HashSet<>();
		q.push(start);
		visit.add(start);
		while(!q.isEmpty())
		{
			Node x = q.pop();
			System.out.println(x.val);
			for(Node nb:x.nbs) 
			{
				if(!visit.contains(nb))
				{
					q.push(nb);
				}
			}
		}
	}
}
class BFS
{	
	public static void bfs(Node start)
	{
		Queue<Node> q = new LinkedList<>();
		Set<Node> visit = new HashSet<>();
		q.add(start);
		visit.add(start);
		while(!q.isEmpty())
		{
			Node x = q.poll();
			System.out.println(x.val);
			for(Node nb:x.nbs) 
			{
				if(!visit.contains(nb))
				{
					q.offer(nb);
				}
			}
		}
	}
}

public class Main {
    public static void main(String[] args) {
        // Create nodes
        Node node0 = new Node(0);
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);

        // Create edges
        node0.addNbs(node1);
        node0.addNbs(node2);
        node1.addNbs(node3);
        node2.addNbs(node4);

        // Create graph
        Graph graph = new Graph();
        graph.addNode(node0);
        graph.addNode(node1);
        graph.addNode(node2);
        graph.addNode(node3);
        graph.addNode(node4);

        // Perform DFS
        // System.out.println("DFS Traversal:");
        // DFS.dfs(node0);
        System.out.println("BFS Traversal:");
        DFS.dfs(node0);
    }
}