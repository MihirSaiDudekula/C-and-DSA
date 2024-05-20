import java.util.*;

class DFS {
    public static void dfs(Node start) {
        Set<Node> visited = new HashSet<>();
        Stack<Node> stack = new Stack<>();

        visited.add(start);
        stack.push(start);

        while (!stack.isEmpty()) {
            Node current = stack.pop();
            System.out.println("Visited node: " + current.val);

            for (Node neighbor : current.neighbors) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    stack.push(neighbor);
                }
            }
        }
    }
}
