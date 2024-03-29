// https://www.acmicpc.net/problem/1463

#include <stdio.h>
#include <stdlib.h>

#define min(a,b) a < b ? a : b

int main()
{
	int N;
	int* dp;

	scanf("%d", &N);
	dp = (int*)calloc(N+1, sizeof(int));

	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	printf("%d\n", dp[N]);

	free(dp);

	return 0;
}