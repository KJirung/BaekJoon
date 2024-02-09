// https://www.acmicpc.net/problem/1931

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}time;

int compare(const void* first, const void* second)
{
	time a = *(time*)first;
	time b = *(time*)second;

	if (a.y > b.y)
		return 1;
	else if (a.y == b.y) {
		if (a.x > b.x)
			return 1;
		else
			return -1;
	}
	else
		return -1;

}

int main()
{
	time arr[100000];
	int n;
	int count = 1;
	int a;


	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	qsort(arr, n, sizeof(time), compare);

	a = arr[0].y;
	for (int i = 1; i < n; i++) {
		if (a <= arr[i].x){
			a = arr[i].y;
			count++;
		}
	}

	printf("%d", count);

	return 0;

}