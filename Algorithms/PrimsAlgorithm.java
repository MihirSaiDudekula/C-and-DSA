import java.util.*;

class Node {
  //each node has a value
  int val;
  //then it has a list of edges, which itself are objects. the name of this list is nbs - neighbours 
  List < Edge > nbs; // list of edges to neighbors

  //constructor to construct the node
  public Node(int val) {
    this.val = val;
    this.nbs = new ArrayList < > ();
  }

  //addEdge function creates a new edge by calling the constructor of edge class which takes from which node , 
  //to which node and weight of the edge, and adds it to the nbs list 
  public void addEdge(Node neighbor, int weight) {
    this.nbs.add(new Edge(this, neighbor, weight));
  }
}

class Edge {
  //edge has the properties : from which node , 
  // to which node and weight of the edge, and adds it to the nbs list
  Node from;
  Node to;
  int weight;

  //constructor - which was called when we wanted to add edge for a node     
  public Edge(Node from, Node to, int weight) {
    this.from = from;
    this.to = to;
    this.weight = weight;
  }
}

class Graph {
  //graph is simply a list of nodes 
  List < Node > nodes;

  public Graph() {
    this.nodes = new ArrayList < > ();
  }

  public void addNode(Node n) {
    nodes.add(n);
  }

  // Function to add weighted edge
  public void addEdge(Node from, Node to, int weight) {
    from.addEdge(to, weight);
    to.addEdge(from, weight); // Assuming undirected graph
  }

  // Prim's algorithm to find Minimum Spanning Tree (MST)
  public List < Edge > primMST(Node start) {
    // Set to keep track of visited nodes
    Set < Node > visited = new HashSet < > ();

    // List to store edges of the Minimum Spanning Tree (MST)
    List < Edge > mst = new ArrayList < > ();

    // Priority queue to store edges sorted by weight
    PriorityQueue < Edge > minHeap = new PriorityQueue < > (Comparator.comparingInt(e -> e.weight));

    // Start the Prim's algorithm by visiting the start node
    visit(start, visited, minHeap);

    // Continue until all nodes are visited or priority queue is empty
    while (!minHeap.isEmpty()) {
      // Extract the edge with the smallest weight from the priority queue
      Edge edge = minHeap.poll();

      // Nodes at either ends of the edge that we got from the above min poll 
      Node u = edge.from;
      Node v = edge.to;

      // If both nodes are already visited, skip this edge
      if (visited.contains(u) && visited.contains(v)) {
        continue;
      }

      // Add the edge to the MST
      mst.add(edge);

      // Determine the next node to visit
      Node next = visited.contains(u) ? v : u;

      // Visit the next node
      visit(next, visited, minHeap);
    }

    // Return the Minimum Spanning Tree (MST) edges
    return mst;
  }

  // Helper method to visit a node and add its edges to the priority queue
  private void visit(Node node, Set < Node > visited, PriorityQueue < Edge > minHeap) {
    // Mark the node as visited
    visited.add(node);

    // Iterate through all edges of the current node
    for (Edge edge: node.nbs) {
      // If the edge leads to an unvisited node, add it to the priority queue
      if (!visited.contains(edge.to)) {
        minHeap.offer(edge);
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

    // Create graph
    Graph graph = new Graph();
    graph.addNode(node0);
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);
    graph.addNode(node4);

    // Create weighted edges
    graph.addEdge(node0, node1, 2);
    graph.addEdge(node0, node2, 3);
    graph.addEdge(node1, node3, 4);
    graph.addEdge(node2, node4, 1);

    // Perform Prim's algorithm to find MST
    List < Edge > mst = graph.primMST(node0);

    // Print MST edges
    System.out.println("Minimum Spanning Tree (MST) using Prim's Algorithm:");
    for (Edge edge: mst) {
      System.out.println(edge.from.val + " - " + edge.to.val + " : " + edge.weight);
    }
  }
}
