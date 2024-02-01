// https://www.acmicpc.net/problem/11053

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

int main()
{
	int N;
	int* dp;
	int* arr;
	int i,j;
	int max=0;

	scanf("%d", &N);
	dp = (int*)calloc(N, sizeof(int));
	arr = (int*)calloc(N, sizeof(int));
	
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j])
				dp[i] = dp[j];	
		}
		dp[i] += 1;
	}

	for (i = 0; i < N; i++) {
		if (max < dp[i])
			max = dp[i];
	}

	printf("%d", max);

	free(arr);
	free(dp);

	return 0;

	
}