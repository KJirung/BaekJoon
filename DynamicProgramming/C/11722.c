// https://www.acmicpc.net/problem/11722

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int* dp;
    int* arr;
    int i, j;
    int max = 0;

    scanf("%d", &N);
    dp = (int*)calloc(N, sizeof(int));
    arr = (int*)calloc(N, sizeof(int));

    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < N; i++) {
        dp[i] = 1;  // 초기값을 1로 설정
        for (j = 0; j < i; j++) {
            if (arr[i] < arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    for (i = 0; i < N; i++) {
        if (max < dp[i])
            max = dp[i];
    }

    printf("%d", max);

    free(arr);
    free(dp);

    return 0;
}
