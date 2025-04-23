#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// colors
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

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
                printf("%sError:%s Array size must be a positive integer\n", RED, RESET);
                return 1;
            }
        }
    }
    
    printf("%s Processing array of size %d %s\n", CYAN, n, RESET);
    
    
    if (show_time) {
        printf("%sStarting timer...%s\n", YELLOW, RESET);
        start = clock();
    }
    
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("%sMemory allocation failed!%s\n", RED, RESET);
        return 1;
    }
    
    // fill array with sequential integers from 1 to n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // gauss addition of sequence of consecutive natural numbers
    int sum = n * (n + 1) / 2;
    
    printf("%sSum of array = %s%d%s\n", GREEN, MAGENTA, sum, RESET);
    
    free(arr);
    
    if (show_time) {
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%sTime taken: %s%f%s seconds%s\n", YELLOW, BLUE, cpu_time_used, YELLOW, RESET);
    }
    return 0;
}
