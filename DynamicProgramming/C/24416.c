// https://www.acmicpc.net/problem/24416

#include <stdio.h>

int ar[50] = { 0, };
int code1, code2;
int fib(int n) {
	if (n == 1 || n == 2) {
		code1++;
		return 1;
	}
	else
		return (fib(n - 1) + fib(n - 2));
}

void fibonacci(int n) {
	ar[1] = 1;
	ar[2] = 1;
	for (int i = 3; i <= n; i++) {
		code2++;
		ar[i] = ar[i - 1] + ar[i - 2];
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	fib(n);
	fibonacci(n);

	printf("%d %d", code1, code2);

	return 0;

}