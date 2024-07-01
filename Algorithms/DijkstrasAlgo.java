import java.util.*;

// Node class represents a node in the graph
class Node {
    int val; // Node value
    List<Edge> nbs; // List of edges (neighbors)

    // Constructor to initialize a node with a value
    public Node(int val) {
        this.val = val;
        this.nbs = new ArrayList<>();
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
    public Map<Node, Integer> dijkstra(Node start) {
        // Map to store shortest distances from start node to each node
        Map<Node, Integer> distances = new HashMap<>();
        
        // Priority queue to fetch nodes with the smallest known distance
        PriorityQueue<NodeDistancePair> minHeap = new PriorityQueue<>(Comparator.comparingInt(p -> p.distance));
    
        // Initialize distances to all nodes as infinity (Integer.MAX_VALUE)
        for (Node node : nodes) {
            distances.put(node, Integer.MAX_VALUE);
        }
    
        // Distance from start node to itself is 0
        distances.put(start, 0);
        
        // Add start node to the priority queue with distance 0
        minHeap.offer(new NodeDistancePair(start, 0));
    
        // Process nodes in the priority queue until it is empty
        while (!minHeap.isEmpty()) {
            // Extract the node with the smallest distance from the priority queue
            NodeDistancePair nd = minHeap.poll();
            Node u = nd.node;
            int dist = nd.distance;
    
            // If the extracted distance is greater than the stored distance, skip processing
            if (distances.get(u) < dist) {
                continue;
            }
    
            // Iterate through all neighboring edges of the current node
            for (Edge edge : u.nbs) {
                Node v = edge.to;
                int weight = edge.weight;
                int newDist = dist + weight;
    
                // If a shorter path to node v is found, update its distance and add to the priority queue
                if (newDist < distances.get(v)) {
                    distances.put(v, newDist);
                    minHeap.offer(new NodeDistancePair(v, newDist));
                }
            }
        }
    
        // Return the map of shortest distances from the start node
        return distances;
    }
    
    // Helper class to pair a node with its distance
    private static class NodeDistancePair {
        Node node;
        int distance;
    
        // Constructor to initialize a NodeDistancePair with node and distance
        public NodeDistancePair(Node node, int distance) {
            this.node = node;
            this.distance = distance;
        }
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
        Map<Node, Integer> shortestDistances = graph.dijkstra(node0);

        // Print shortest distances
        System.out.println("Shortest distances from node " + node0.val + ":");
        for (Node node : shortestDistances.keySet()) {
            System.out.println("To node " + node.val + ": " + shortestDistances.get(node));
        }

        // Example: Find shortest path length from node0 to node3
        Node endNode = node3;
        int shortestPathLength = shortestDistances.get(endNode);
        System.out.println("Shortest path length from node " + node0.val + " to node " + endNode.val + ": " + shortestPathLength);
    }
}
