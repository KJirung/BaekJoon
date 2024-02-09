// https://www.acmicpc.net/problem/2217

#include <stdio.h>
#include <stdlib.h>

// 오름차순 정렬
int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second) return 1;
	else if (*(int*)first < *(int*)second) return -1;
	else return 0;
}

int main()
{
	int N;
	int* arr;
	int max = 0;
	int cnt;

	scanf("%d", &N);
	cnt = N;
	arr = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	qsort(arr, N, sizeof(int), compare);


	for (int i = 0; i < N; i++) {
		if (max < arr[i] * (N - i))
			max = arr[i] * (N - i);
	}

	printf("%d", max);

	free(arr);

	return 0;
}