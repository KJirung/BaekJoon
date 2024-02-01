// https://www.acmicpc.net/problem/10844

#include <stdio.h>

int main()
{
	int N;
	int dp[101][10] = { 0, };	// 동적계획법에 사용할 dp테이블
	int sum = 0;

	scanf("%d", &N);	// 자릿수(N)을 입력받음

	for (int i = 1; i < 10; i++)	// 
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++)
		sum = (sum + dp[N][i]) % 1000000000;

	printf("%d", sum);

	return 0;





}