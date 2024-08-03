import java.util.*;

// Node class represents a node in the graph
class Node {
    int val; // Node value
    List<Edge> nbs; // List of edges (neighbors)
    int dist;

    // Constructor to initialize a node with a value
    public Node(int val) {
        this.val = val;
        this.nbs = new ArrayList<>();
        this.dist = Integer.MAX_VALUE;
    }

    // Method to add a neighbor (edge) to the node with a specified weight
    public void addEdge(Node neighbor, int weight) {
        nbs.add(new Edge(this, neighbor, weight));
    }
}

// Edge class represents an edge between two nodes with a weight
class Edge {
    Node from; // Starting node of the edge
    Node to; // Ending node of the edge
    int weight; // Weight of the edge

    // Constructor to initialize an edge with starting node, ending node, and weight
    public Edge(Node from, Node to, int weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}

// Graph class represents a collection of nodes and edges
class Graph {
    List<Node> nodes; // List of nodes in the graph

    // Constructor to initialize an empty graph
    public Graph() {
        this.nodes = new ArrayList<>();
    }

    // Method to add a node to the graph
    public void addNode(Node n) {
        nodes.add(n);
    }

    // Method to add a weighted edge between two nodes in the graph
    public void addEdge(Node from, Node to, int weight) {
        from.addEdge(to, weight);
        // Assuming undirected graph, adding both directions
        to.addEdge(from, weight);
    }

    // Dijkstra's algorithm to find shortest path from start node to all nodes
    public List<Node> dijkstra(Node start) {
        // Map to store shortest distances from start node to each node
        // Map<Node, Integer> distances = new HashMap<>();
        
        // Priority queue to fetch nodes with the smallest known distance
        PriorityQueue<Node> minHeap = new PriorityQueue<>(Comparator.comparingInt(n -> n.dist));
    
        // Initialize distances to all nodes as infinity (Integer.MAX_VALUE)
        // for (Node node : nodes) {
        //     distances.put(node, Integer.MAX_VALUE);
        // }
    
        // Distance from start node to itself is 0
        start.dist=0;
        
        // Add start node to the priority queue with distance 0
        minHeap.offer(start);
    
        // Process nodes in the priority queue until it is empty
        while (!minHeap.isEmpty()) {
            // Extract the node with the smallest distance from the priority queue
            Node n = minHeap.poll();
            // int dist = nd.distance;
    
            // If the extracted distance is greater than the stored distance, skip processing
            if (n.dist < n.dist) {
                continue;
            }
    
            // Iterate through all neighboring edges of the current node
            for (Edge edge : n.nbs) {
                Node v = edge.to;
                int weight = edge.weight;
                int newDist = n.dist + weight;
    
                // If a shorter path to node v is found, update its distance and add to the priority queue
                if (newDist < v.dist) {
                    v.dist = newDist;
                    minHeap.offer(v);
                }
            }
        }
    
        // Return the map of shortest distances from the start node
        return nodes;
    }
}

// Main class for testing Dijkstra's algorithm
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

        // Perform Dijkstra's algorithm from node0
        List<Node> shortestDistances = graph.dijkstra(node0);

        // Print shortest distances
        System.out.println("Shortest distances from node " + node0.val + ":");
        for (Node node : shortestDistances) {
            System.out.println("To node " + node.val + ": " + node.dist);
        }
    }
}

