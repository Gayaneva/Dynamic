#include <stdio.h>
#include <stdlib.h>

float* allocate_float(int n) {
    float* arr = (float*)calloc(n, sizeof(float)); 
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return arr;
}

int main() {
    int n = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);

    float* arr = allocate_float(n);
    if (arr == NULL) {
        return 1; 
    }

    printf("Enter %d float values\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("The array elements are\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}

