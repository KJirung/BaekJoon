// https://www.acmicpc.net/problem/1932

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

int main()
{
	int n;
	int* arr;
	int sum = 0;
	
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int best = arr[0];
	for (int i = 0; i < n; i++) {
		sum = max(arr[i], sum + arr[i]);
		best = max(best, sum);
	}

	printf("%d", best);

	free(arr);

	return 0;
		
}