#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* custom_realloc(void* ptr, size_t new_size) {
    if (ptr == NULL) {
        return malloc(new_size);
    }
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        printf("Reallocation failed\n");
        return NULL;
    }

    memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}

int main() {
    int n = 0;
    int new_n = 0;
    printf("Enter size of array ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter new array size ");
    scanf("%d", &new_n);

    int* resized_arr = (int*)custom_realloc(arr, new_n * sizeof(int));
    if (!resized_arr) {
        free(arr);
        return 1;
    }
    arr = resized_arr;

    for (int i = n; i < new_n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Updated array\n");
    for (int i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

