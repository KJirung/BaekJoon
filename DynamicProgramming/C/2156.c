// https://www.acmicpc.net/problem/2156

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    int* amount;
    int* dp;
    int temp;

    scanf("%d", &n);

    amount = (int*)calloc(n + 1, sizeof(int));
    dp = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++)
        scanf("%d", &amount[i]);

    dp[1] = amount[1];
    dp[2] = amount[1] + amount[2];

    for (int i = 3; i <= n; i++) {
        temp = max(dp[i - 3] + amount[i - 1] + amount[i], dp[i - 2] + amount[i]);
        dp[i] = max(temp, dp[i - 1]);
    }

    printf("%d", dp[n]);

    free(dp);
    free(amount);

    return 0;
}
