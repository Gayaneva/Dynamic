#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocate_string(int size) {
      char* str = (char*)malloc((size + 1) * sizeof(char)); 
       if (str == NULL) {
           printf("Memory allocation failed");
           return NULL;
    }
    return str;
}

int main() {
    int size;
    printf("Enter maximum string length ");
    scanf("%d", &size);

    char* str = allocate_string(size);
    if (str == NULL) {
        return 1; 
    }

    getchar(); 
    
    printf("Enter the string ");
    fgets(str, size + 1, stdin);

    str[strcspn(str, "\n")] = '\0';
    printf("You entered %s\n", str);
    printf("String length is %zu\n", strlen(str));

    free(str); 
    return 0;
}

