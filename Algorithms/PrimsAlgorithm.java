import java.util.*;

class Node {
    //each node has a value
    int val;
    //then it has a list of edges, which itself are objects. the name of this list is nbs - neighbours 
    List<Edge> nbs; // list of edges to neighbors

    //constructor to construct the node
    public Node(int val) {
        this.val = val;
        this.nbs = new ArrayList<>();
    }

    //addEdge function creates a new edge by calling the constructor of edge class which takes from which node , 
    //to which node and weight of the edge, and adds it to the nbs list 
    public void addEdge(Node neighbor, int weight) {
        nbs.add(new Edge(this, neighbor, weight));
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
    List<Node> nodes;

    public Graph() {
        this.nodes = new ArrayList<>();
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
    public List<Edge> primMST(Node start) {
        Set<Node> visited = new HashSet<>();
        List<Edge> mst = new ArrayList<>();
        PriorityQueue<Edge> minHeap = new PriorityQueue<>(Comparator.comparingInt(e -> e.weight));

        visit(start, visited, minHeap);

        while (!minHeap.isEmpty()) {
            Edge edge = minHeap.poll();
            Node u = edge.from;
            Node v = edge.to;

            if (visited.contains(u) && visited.contains(v)) {
                continue;
            }

            mst.add(edge);
            Node next = visited.contains(u) ? v : u;
            visit(next, visited, minHeap);
        }

        return mst;
    }

    private void visit(Node node, Set<Node> visited, PriorityQueue<Edge> minHeap) {
        visited.add(node);
        for (Edge edge : node.nbs) {
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
        List<Edge> mst = graph.primMST(node0);

        // Print MST edges
        System.out.println("Minimum Spanning Tree (MST) using Prim's Algorithm:");
        for (Edge edge : mst) {
            System.out.println(edge.from.val + " - " + edge.to.val + " : " + edge.weight);
        }
    }
}
