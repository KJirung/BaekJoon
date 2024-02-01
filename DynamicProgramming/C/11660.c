// https://www.acmicpc.net/problem/11660

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    int** arr_part;
    int a, b, c, d;

    scanf("%d %d", &N, &M);

    
    arr_part = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        arr_part[i] = (int*)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        int row_sum = 0;
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr_part[i][j]);
            row_sum += arr_part[i][j];
            arr_part[i][j] = row_sum + ((i > 0) ? arr_part[i - 1][j] : 0);
        }
    }

    for (int t = 0; t < M; t++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a -= 1, b -= 1, c -= 1, d -= 1;

        int total_sum = arr_part[c][d];
        if (a > 0) {
            total_sum -= arr_part[a - 1][d];
        }
        if (b > 0) {
            total_sum -= arr_part[c][b - 1];
        }
        if (a > 0 && b > 0) {
            total_sum += arr_part[a - 1][b - 1];
        }

        printf("%d\n", total_sum);
    }

    for (int i = 0; i < N; i++) {
        free(arr_part[i]);
    }
    free(arr_part);

    return 0;
}
