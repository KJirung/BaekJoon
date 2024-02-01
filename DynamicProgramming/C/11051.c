// https://www.acmicpc.net/problem/11051

#include <stdio.h>
#include <stdlib.h>
#define mod 10007

#define min(a, b) ((a) > (b) ? (b) : (a))

int main() {
    int N, K;
    int i, j;
    int** dp;

    scanf("%d %d", &N, &K);

    dp = (int**)calloc(N + 1, sizeof(int*));
    for (i = 0; i <= N + 1; i++) {
        dp[i] = (int*)calloc(K + 1, sizeof(int*));
    }

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= min(i, K); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }

    printf("%d", dp[N][K]);

    return 0;
}
