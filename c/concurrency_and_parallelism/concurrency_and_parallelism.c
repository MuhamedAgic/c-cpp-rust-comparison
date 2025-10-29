#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 10;
    int *vec = malloc(n * sizeof(int));
    int *result = malloc(n * sizeof(int));
    int threshold = 10;
    int count = 0;

    for(int i = 0; i < n; i++) vec[i] = i + 1;

    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        int sq = vec[i] * vec[i];
        if(sq >= threshold) result[i] = sq;
        else result[i] = 0;  // Mark filtered out with 0
    }

    printf("Filtered squares >= %d:\n", threshold);
    for(int i = 0; i < n; i++)
        if(result[i] != 0) printf("%d ", result[i]);
    printf("\n");

    free(vec);
    free(result);
    return 0;
}
