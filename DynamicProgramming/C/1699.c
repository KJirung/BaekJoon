// https://www.acmicpc.net/problem/1699

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) a > b ? b : a

int main()
{
	int N;
	int* dp;

	scanf("%d", &N);
	dp = (int*)malloc(sizeof(int) * (N + 1));

	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[N]);

	free(dp);

	return 0;
}