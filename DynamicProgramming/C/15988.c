// https://www.acmicpc.net/problem/15988

#include <stdio.h>
#include <stdlib.h>

#define mod 1000000009
#define ll long long

int main()
{
	ll* dp;		// dp 테이블 포인터
	int n;		// 각 테스트 케이스별 n값을 저장
	int T;		// 테스트 케이스의 개수

	scanf("%d", &T);	

	while (T--) {
		scanf("%d", &n);

		// 동적 할당
		dp = (ll*)malloc((n + 3) * sizeof(ll));		
		
		// 초기값 설정
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;	// 구한 점화식 적용
		printf("%d\n", dp[n]%mod);
		free(dp);	// 매 케이스마다 동적할당 후 메모리 해제
	}

	return 0;

}