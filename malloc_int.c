#include <stdio.h>
#include <stdlib.h>

int* allocate_arr(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Allocation failed ");
        return NULL;
    }
    return arr;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int* arr = allocate_arr(size);
    if (arr == NULL) {
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); 
   
}

