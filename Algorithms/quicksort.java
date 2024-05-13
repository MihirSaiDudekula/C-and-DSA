class QuickSort {
    
    public static void swap(int[] arr,int pos1,int pos2)
    {
        int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }
    
    public static int partition(int[] arr, int low, int high)
    {
    }
    
    public static void quickSort(int[] arr, int low, int high)
    {
        int pivot = arr[high];
        int j = high-1;
        int i = low;
        while(i<=j)
        {
            while(arr[i]<= pivot && i<= high - 1)
            {
                i++;
            }
            while(arr[j]>=pivot && arr[j]>=low-1)
            {
                j++;
            }
            swap(arr,i,j);
        }
        
        // if (low < high) {
        //     int pi = partition(arr, low, high);
        //     quickSort(arr, low, pi - 1);
        //     quickSort(arr, pi + 1, high);
        // }
    }

    
    public static void main(String[] args) {
        int[] arr = {5, 3, 7, 2, 8, 4}; // Example unsorted array

        System.out.println("Original array:");
        printArray(arr);

        quickSort(arr, 0, arr.length - 1); // Start quicksort with pivot as the last element

        System.out.println("Sorted array:");
        printArray(arr);
    }

    public static void printArray(int[] arr) 
    {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

}
