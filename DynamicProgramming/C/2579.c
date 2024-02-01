// https://www.acmicpc.net/problem/2579

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a > b ? a : b

int main()
{
	int N;
	int* dp;
	int* stair;

	scanf("%d", &N);

	dp = (int*)calloc(N+1, sizeof(int));
	stair = (int*)calloc(N+1, sizeof(int));

	for (int i = 1; i < N + 1; i++)
		scanf("%d", &stair[i]);

	if (N == 1) printf("%d", stair[1]);
	else if (N == 2) printf("%d", stair[1] + stair[2]);
	else {
		dp[1] = stair[1];
		dp[2] = stair[1] + stair[2];
		for (int i = 3; i < N + 1; i++)
			dp[i] = max(dp[i - 2] + stair[i], stair[i] + stair[i - 1] + dp[i - 3]);
		printf("%d", dp[N]);
	}

	free(dp);
	free(stair);

	return 0;

}