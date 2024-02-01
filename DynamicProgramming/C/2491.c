// https://www.acmicpc.net/problem/2491

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

int main()
{
	int N;
	int* dp1;
	int* dp2;
	int* arr;
	int max_value1 = 0;
	int max_value2 = 0;

	scanf("%d", &N);
	dp1 = (int*)calloc(N, sizeof(int));
	dp2 = (int*)calloc(N, sizeof(int));
	arr = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		dp1[i] = 1;
		dp2[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] >= arr[i - 1])
			dp1[i] += dp1[i - 1];
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] <= arr[i - 1])
			dp2[i] += dp2[i - 1];
	}

	for (int i = 0; i < N; i++) {
		if (max_value1 < dp1[i])
			max_value1 = dp1[i];
	}

	for (int i = 0; i < N; i++) {
		if (max_value2 < dp2[i])
			max_value2 = dp2[i];
	}

	printf("%d", max(max_value1, max_value2));
	

	free(dp1);
	free(dp2);
	free(arr);

	return 0;
	
}