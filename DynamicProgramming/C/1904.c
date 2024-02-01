// https://www.acmicpc.net/problem/1904

#include <stdio.h>
#define Max 1000001


int dp[Max];

int main()
{
	int N;
	
	scanf("%d", &N);
	
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < Max; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%15746;

	printf("%d", dp[N]);

	return 0;


}