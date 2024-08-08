class Knapsack {
    // Function to solve the 0/1 Knapsack problem
    public static int knapsack(int[] weights, int[] profit, int capacity) {
        int n = weights.length; // Number of items
        int[][] table = new int[n + 1][capacity + 1]; // DP table initialization

        // Build the DP table
        for (int currentItem = 0; currentItem <= n; currentItem++) { // Loop through each item
            for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++) { // Loop through each capacity
                if (currentItem == 0 || currentCapacity == 0) { // Base case
                    table[currentItem][currentCapacity] = 0; // No items or zero capacity
                } else {
                    int weightOfCurrentItem = weights[currentItem - 1]; // Weight of the current item
                    int profitWithoutCurrentItem = table[currentItem - 1][currentCapacity]; // Profit without including the current item
                    
                    if (weightOfCurrentItem <= currentCapacity) { // If current item can fit in the capacity
                        int profitOfThisWeight = profit[currentItem - 1]; // Profit of the current item
                        int weightOfRemainCapacity = currentCapacity - weightOfCurrentItem; // Remaining capacity after including the item
                        int profitOfRemainingCapacity = table[currentItem - 1][weightOfRemainCapacity]; // Profit with the remaining capacity

                        // Update the table with the maximum profit of including or not including the current item
                        table[currentItem][currentCapacity] = Math.max(profitOfThisWeight + profitOfRemainingCapacity, profitWithoutCurrentItem);
                    } else {
                        // Current item cannot fit, so carry forward the profit from previous item
                        table[currentItem][currentCapacity] = profitWithoutCurrentItem;
                    }
                }
            }
        }

        // Return the maximum profit with the given capacity
        return table[n][capacity];
    }

    public static void main(String[] args) {
        int[] weights = {1, 3, 4, 5}; // Weights of the items
        int[] profit = {1, 4, 5, 7}; // Profits of the items
        int capacity = 7; // Maximum capacity of the knapsack

        // Calculate the maximum value that can be obtained
        int maxProfit = knapsack(weights, profit, capacity);
        // Print the maximum profit
        System.out.println("Maximum profit in Knapsack = " + maxProfit);
    }
}
