// https://www.acmicpc.net/problem/12865

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

int **dp;

int knapsack(int W, int **bg, int n)
{
    int valWith, valWithout;

    dp = (int **)calloc(n + 1, sizeof(int *));

    for (int i = 0; i < n + 1; i++)
        dp[i] = (int *)calloc(W + 1, sizeof(int));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (bg[i - 1][0] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                valWith = bg[i - 1][1] + dp[i - 1][j - bg[i - 1][0]];
                valWithout = dp[i - 1][j];
                dp[i][j] = max(valWith, valWithout);
            }
        }
    }

    int result = dp[n][W];

    // dp에 할당된 메모리 해제
    for (int i = 0; i < n + 1; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main()
{
    int N, K;
    int **bag;
    int result;

    scanf("%d %d", &N, &K);

    bag = (int **)calloc(N, sizeof(int *));

    for (int i = 0; i < N; i++)
        bag[i] = (int *)calloc(2, sizeof(int));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &bag[i][j]);
        }
    }

    result = knapsack(K, bag, N);

    printf("%d", result);

    for (int i = 0; i < N; i++)
        free(bag[i]);
    free(bag);

    return 0;
}
