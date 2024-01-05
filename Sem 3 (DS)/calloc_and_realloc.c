#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr;
	int n, i;

	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Entered number of elements: %d\n", n);

	// Dynamically allocate memory using malloc()
	ptr = (int*)calloc(n,sizeof(int));

    // Store the elements in the array
    for (i = 0; i < n; ++i) {
        *(ptr+i) = i + 10;
    }

    // Print the elements of the array
    printf("The elements of the array are: ");
    for (i = 0; i < n; ++i) {
        // printf("%d ", ptr[i]);
        printf("%d ", *(ptr+i));
    }

    // Enlarge array to add 5 more elements
    int  n1 = n + 5;
    int *ptr2 = (int*)realloc(ptr, n1*sizeof(int));

    // Add 5 more elements to the array.
    for (i = n; i < n1; ++i) {
        ptr[i] = i + 10;
    }

     // New array size
        // Print the elements of the array
    printf("\nThe elements of the enlarged array are: ");
    for (i = 0; i < n1; ++i) {
        printf("%d ", ptr2[i]);
    }

    // Freeing the memory
    free(ptr2);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int n, i;

    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));

    // Store the elements in the original array
    for (i = 0; i < n; ++i) {
        *(ptr + i) = i + 10;
    }

    // Print the elements of the original array
    printf("The elements of the array are: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", *(ptr + i));
    }

    // Enlarge array to add 5 more elements
    int n1 = n + 5;
    int* ptr2 = (int*)realloc(ptr, n1 * sizeof(int));

    // if (ptr2 != NULL) {
    //     // Use ptr2 to access the reallocated memory

    //     ptr = ptr2; // Update ptr to point to the new memory

    //     // Add 5 more elements to the array.
    //     for (i = n; i < n1; ++i) {
    //         ptr[i] = i + 10;
    //     }

        for (i = n; i < n1; ++i) {
            ptr2[i] = i + 10;
        }
        // Print the elements of the enlarged array
        printf("\nThe elements of the enlarged array are: ");
        for (i = 0; i < n1; ++i) {
            printf("%d ", ptr[i]);
        }

        // Freeing the memory
        free(ptr2);
    }
    return 0;
}


