// https://www.acmicpc.net/problem/9461

#include <stdio.h>

#define ll long long

int main()
{
	ll int arr[200] = { 1,1,1,2,2 };		// 첫 번째 삼각형부터 다섯번째 삼각형까지의 한 변의 길이
	int N, T;		// 테스트 케이스의 개수(T), 삼각형의 인덱스(N)

	scanf("%d", &T);

	for (int i = 5; i < 100; i++) {
		arr[i] = arr[i - 5] + arr[i - 1];		// i번째 삼각형의 한 변의 길이는 i-5번째 삼각형의 한변의 길이 + i-1번째 삼각형의 한변의 길이
	}

	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", arr[N - 1]);	
	}

	return 0;


}