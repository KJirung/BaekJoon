// https://www.acmicpc.net/problem/15624

#include <stdio.h>
#include <stdlib.h>

#define ll long long

int main()
{
	int N;
	ll* f;

	scanf("%d", &N);
	f = (ll*)calloc(N+2, sizeof(ll));

	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= N; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
	}

	printf("%lld", f[N]);

	free(f);

	return 0;

}