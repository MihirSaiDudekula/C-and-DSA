import java.util.*;

class Pair<U, V> {
    private final U key;
    private final V value;

    public Pair(U key, V value) {
        this.key = key;
        this.value = value;
    }

    public U getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

class Node {
    int val;
    List<Pair<Node, Integer>> nbs = new ArrayList<>(); // List of edges to neighbors

    public Node(int val) {
        this.val = val;
    }

    public void addEdge(Node neighbor, int weight) {
        this.nbs.add(new Pair<>(neighbor, weight));
    }
}

class GraphTry {
    List<Node> nodes;

    public GraphTry() {
        this.nodes = new ArrayList<>();
    }

    public void addNode(Node n) {
        nodes.add(n);
    }

    public List<Pair<Node, Integer>> primsAlgorithm() {
        Set<Node> visited = new HashSet<>();
        PriorityQueue<Pair<Node, Integer>> minHeap = new PriorityQueue<>(Comparator.comparingInt(Pair::getValue));
        List<Pair<Node, Integer>> mst = new ArrayList<>();

        // Start from the first node
        Node startNode = nodes.get(0);
        visited.add(startNode);

        // Add all edges from the start node to the heap
        for (Pair<Node, Integer> edge : startNode.nbs) {
            minHeap.add(new Pair<>(edge.getKey(), edge.getValue()));
        }

        while (!minHeap.isEmpty()) {
            // Get the edge with the minimum weight
            Pair<Node, Integer> currentEdge = minHeap.poll();
            Node currentNode = currentEdge.getKey();

            // If the node has already been visited, skip it
            if (visited.contains(currentNode)) {
                continue;
            }

            // Mark the node as visited and add the edge to the MST
            visited.add(currentNode);
            mst.add(currentEdge);

            // Add all edges from the current node to the heap
            for (Pair<Node, Integer> edge : currentNode.nbs) {
                if (!visited.contains(edge.getKey())) {
                    minHeap.add(new Pair<>(edge.getKey(), edge.getValue()));
                }
            }
        }

        return mst;
    }

    public static void main(String[] args) {
        GraphTry graph = new GraphTry();

        Node node0 = new Node(0);
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);

        node0.addEdge(node1, 10);
        node0.addEdge(node2, 6);
        node0.addEdge(node3, 5);

        node1.addEdge(node0, 10);
        node1.addEdge(node3, 15);

        node2.addEdge(node0, 6);
        node2.addEdge(node3, 4);

        node3.addEdge(node0, 5);
        node3.addEdge(node1, 15);
        node3.addEdge(node2, 4);

        graph.addNode(node0);
        graph.addNode(node1);
        graph.addNode(node2);
        graph.addNode(node3);

        List<Pair<Node, Integer>> mst = graph.primsAlgorithm();

        for (Pair<Node, Integer> edge : mst) {
            System.out.println("Edge: (" + edge.getKey().val + ", " + edge.getValue() + ")");
        }
    }
}
