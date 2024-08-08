public class Knapsack {

    // Function to solve the 0/1 Knapsack problem
    public static int knapsack(int[] weights, int[] values, int capacity) {
        int n = weights.length; // Number of items
        int[][] dp = new int[n + 1][capacity + 1]; // DP table with (n+1) rows and (capacity+1) columns

        // Build the DP table
        for (int i = 0; i <= n; i++) { // Iterate over each item (0 to n, where i=0 means no items)
            for (int w = 0; w <= capacity; w++) { // Iterate over each weight capacity (0 to capacity)
                if (i == 0 || w == 0) { // Base case: if no items or capacity is 0
                    dp[i][w] = 0; // If there are no items or capacity is 0, the maximum value is 0
                } else if (weights[i - 1] <= w) { // If the current item can fit in the current capacity
                    // Choose the maximum between:
                    // 1. Including the current item: value of the current item + value of the remaining capacity
                    // 2. Not including the current item: value from the previous row (i.e., not taking this item)
                    dp[i][w] = Math.max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
                } else { // If the current item cannot fit in the current capacity
                    dp[i][w] = dp[i - 1][w]; // Carry forward the value from the previous row (i.e., not taking this item)
                }
            }
        }

        // The maximum value that can be obtained with the given capacity
        return dp[n][capacity];
    }

    public static void main(String[] args) {
        int[] weights = { 1, 3, 4, 5 }; // Weights of the items
        int[] values = { 1, 4, 5, 7 }; // Values of the items
        int capacity = 7; // Maximum capacity of the knapsack

        // Calculate the maximum value that can be obtained
        int maxValue = knapsack(weights, values, capacity);
        // Print the maximum value
        System.out.println("Maximum value in Knapsack = " + maxValue);
    }
}
