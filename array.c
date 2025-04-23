#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n = 10;
    int show_time = 0;
    clock_t start, end;
    double cpu_time_used;
    
    // parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--time") == 0 || strcmp(argv[i], "-t") == 0) {
            show_time = 1;
        } else {
            n = atoi(argv[i]);
            if (n <= 0) {
                printf("Array size must be a positive integer\n");
                return 1;
            }
        }
    }
    
    if (show_time) {
        start = clock();
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
    
    if (show_time) {
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken: %f seconds\n", cpu_time_used);
    }
    
    return 0;
}
