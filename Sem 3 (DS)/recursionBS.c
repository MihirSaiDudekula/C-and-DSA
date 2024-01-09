#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
        // checking if there are elements in the subarray
        if (r >= l) {

                // calculating mid point
                int mid = l + (r - l) / 2;

                // If the element is present at the middle itself
                if (arr[mid] == x)
                        return mid;

                // If element is smaller than mid, then it can only
                // be present in left subarray
                if (arr[mid] > x) {
                        return binarySearch(arr, l, mid - 1, x);
                }

                // Else the element can only be present in right
                // subarray
                return binarySearch(arr, mid + 1, r, x);
        }

        // We reach here when element is not present in array
        return -1;
}

// driver code
int main(void)
{
        // taking a sorted array
        int n,i,x;
        printf("\nenter the number of elements\n");
        scanf("%d",&n);
        int arr[n];

        printf("\nenter the elemens in the array\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&arr[i]);        
        }
        printf("\nenter the element to be searched\n");
        scanf("%d",&x);

        // calling binary search
        int index = binarySearch(arr, 0, n, x);

        if (index == -1) {
                printf("Element is not present in array");
        }
        else {
                printf("Element is present at index %d", index);
        }

        return 0;
}



