#include <stdio.h>
#include <stdlib.h>

int main() {

    int* ptr;
    int n = 5, i;

    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated using malloc.\n");

        for (i = 0; i < n; ++i) {
            // Accessing elements using pointer arithmetic
            *(ptr + i) = i + 1;
        }

        printf("The elements of the array are: ");
        for (i = 0; i < n; i++) {
            // Accessing elements using pointer arithmetic
            printf("%d ", *(ptr + i));
        }
        printf("\n");

        // Free the allocated memory
        free(ptr);
    }
    return 0;
}
