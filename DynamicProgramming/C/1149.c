// https://www.acmicpc.net/problem/1149

#include <stdio.h>
#define min(a,b) a > b ? b : a

int dp[1001][3];

int main() {
	int n;
	int ans;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &dp[i][j]);

	for (int i = 1; i < n; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);	// i번째 집을 0번색으로 칠하는 경우(i-1번째 집의 색은 1번색 or 2번색을 선택해야 함)
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);	// i번째 집을 1번색으로 칠하는 경우(i-1번째 집의 색은 0번색 or 2번색을 선택해야 함)
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);	// i번째 집을 2번색으로 칠하는 경우(i-1번째 집의 색은 0번색 or 1번색을 선택해야 함)
	}

	ans = min(dp[n - 1][0], (min(dp[n - 1][1], dp[n - 1][2])));		// 3가지 경우 중 가장 작은 값을 결과값으로 저장

	printf("%d", ans);		// 결과 출력

	return 0;
}