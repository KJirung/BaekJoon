// https://www.acmicpc.net/problem/11399

#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second)
{
	int a = *(int*)first;
	int b = *(int*)second;

	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

int main()
{
	int N;
	int* arr;
	int* result;
	int sum = 0;

	scanf("%d", &N);

	arr = (int*)calloc(N, sizeof(int));
	result = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	qsort(arr, N, sizeof(arr[0]), compare);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			result[i] += arr[j];
	}
	for (int i = 0; i < N; i++)
		sum += result[i];

	printf("%d", sum);

	free(arr);
	free(result);

	return 0;


}