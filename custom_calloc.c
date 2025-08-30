#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* custom_calloc(size_t num, size_t size) {
    void* ptr = malloc(num * size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
  
    memset(ptr, 0, num * size);
    return ptr;
}

int main() {
    int n = 0;
    printf("Enter size ");
    scanf("%d", &n);

    int* arr = (int*)custom_calloc(n, sizeof(int));
    if (arr == NULL) {
        return 1;
    }

  
    printf("Array elements are\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
  
    printf("Enter %d integers\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Elements is\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); 
    return 0;
}

