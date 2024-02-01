// https://www.acmicpc.net/problem/1965

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int* arr;
	int* dp;
	int max = 0;

	scanf("%d", &n);	// 상자의 개수를 입력 받음

	// 상자의 개수만큼 arr,dp 동적 할당
	arr = (int*)calloc(n, sizeof(int));
	dp = (int*)calloc(n, sizeof(int));


	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);	// 각 상자의 크기를 순서대로 입력받음

	for (int i = 0; i < n; i++) {
		dp[i] = 1;		// 각 상자를 선택하는 경우는 기본적으로 1
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)	// 현재 선택한 상자 이전의 상자들 중 현재 선택한 상자의 크기보다 작고, 들어있는 상자의 개수+1이 현재 선택한 상자에 들어있는 개수보다 큰 경우 갱신 
				dp[i] = dp[j] + 1;		// 현재 선택한 상자에 위 조건을 만족하는 상자를 통째로 집어넣음
			if (max < dp[i])
				max = dp[i];			// 현재까지의 최대 개수보다 큰 경우 값을 갱신
		}
	}
		
	printf("%d", max);					// 결과 출력

	// 동적할당 해제
	free(arr);			
	free(dp);

	return 0;

}