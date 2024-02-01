// https://www.acmicpc.net/problem/11057

#include <stdio.h>

int main()
{
	int N;
	int dp[1001][10] = { 0, };
	int sum = 0;


	scanf("%d", &N);

	
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;	// N=1일 때 자릿수별로 경우의 수를 1개씩 가짐

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k]%10007;	// N=i일 때 N[i][j]의 값은 N[i-1][0~j까지의 합]을 하짐
			}
		}
	}

	for (int i = 0; i < 10; i++)
		sum += dp[N][i]%10007;	// N행의 경우의 수의 합을 구함
		

	
	printf("%d", sum%10007);	// 결과 출력

	return 0;

}