// https://www.acmicpc.net/problem/11047

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K;
	int *coin;
	int count = 0;

	scanf("%d %d", &N, &K);

	coin = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++)
		scanf("%d", &coin[i]);

	for (int i = N - 1; i >= 0; i--) {
		count += K / coin[i];
		K %= coin[i];
	}

	printf("%d", count);

	free(coin);

	return 0;
}