import java.util.*;

class Node {
    int val;
    List<Node> nbs; // List of neighbors 

    public Node(int val) {
        this.val = val;
        this.nbs = new ArrayList<>();
    }

    public void addNbs(Node nb) {
        this.nbs.add(nb);
    }
}

class Graph {
    List<Node> nodes;
    Stack<Node> topoorder; // Stack to store the topological order

    public Graph() {
        this.nodes = new ArrayList<>();
        this.topoorder = new Stack<>();
    }

    public void addNode(Node n) {
        nodes.add(n);
    }

    // Main function to perform topological sorting
    public void topoSort() {
        Set<Node> visited = new HashSet<>();
        for (Node n : nodes) {
            if (!visited.contains(n)) {
                dfs(n, visited);
            }
        }
    }

    // Recursive DFS to perform topological sort
    private void dfs(Node start, Set<Node> visited) {
        visited.add(start);
        for (Node neighbor : start.nbs) {
            if (!visited.contains(neighbor)) {
                dfs(neighbor, visited);
            }
        }
        topoorder.push(start); // Push node to stack after visiting all its neighbors
    }

    // Function to print the topological order
    public void printTopoSort() {
        while (!topoorder.isEmpty()) {
            System.out.println(topoorder.pop().val);
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

        // Perform topological sort and print the result
        graph.topoSort();
        System.out.println("Topological order:");
        graph.printTopoSort();
    }
}
