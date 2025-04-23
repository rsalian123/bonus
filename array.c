#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 10;
    
    if (argc > 1) {
        n = atoi(argv[1]);
        if (n <= 0) {
            printf("Array size must be a positive integer\n");
            return 1;
        }
    }
    
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // fill array with sequential integers from 1 to n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // gauss addition of sequence of consecutive natural numbers
    int sum = n * (n + 1) / 2;
    
    printf("Sum of array = %d\n", sum);
    
    free(arr);
    return 0;
}
