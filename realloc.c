#include <stdio.h>
#include <stdlib.h>

int* allocate_int_array(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return arr;
}

int* resize_int_array(int* arr, int new_size) {
    int* temp = (int*)realloc(arr, new_size * sizeof(int));
    if (temp == NULL) {
        printf("Reallocation failed\n");
        return NULL;
    }
    return temp;
}

int main() {
    int n = 0;
    int new_n = 0;
    printf("Enter size of  array ");
    scanf("%d", &n);

    int* arr = allocate_int_array(n);
    if (arr == NULL)
	 return 1;

    printf("Enter %d integers\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to add ");
    scanf("%d", &new_n);

    int total_size = n + new_n;
    int* resized_arr = resize_int_array(arr, total_size);
    if (resized_arr == NULL) {
        free(arr);
        return 1;
    }
    arr = resized_arr;

    printf("Enter %d new integers\n", new_n);
    for (int i = n; i < total_size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Updated array\n");
    for (int i = 0; i < total_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

