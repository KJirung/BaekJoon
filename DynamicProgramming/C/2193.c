// https://www.acmicpc.net/problem/2193

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	long long dp[91];

	scanf("%d", &N);
;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld", dp[N]);


	return 0;
}
