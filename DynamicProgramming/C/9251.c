// https://www.acmicpc.net/problem/9251

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a,b) a > b ? a : b

int** dp;

void LCS(char a[], char b[], int n, int k)
{
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1]+1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

int main()
{
	char a[1000];
	char b[1000];
	int n, k;
	int cnt = 0;

	scanf("%s", &a);
	scanf("%s", &b);

	n = strlen(a);
	k = strlen(b);

	dp = (int**)calloc(n+1, sizeof(int*));
	for (int i = 0; i < n+1; i++)
		dp[i] = (int*)calloc(k+1, sizeof(int));

	LCS(a, b, n, k);

	printf("%d", dp[n][k]);

	for (int i = 0; i < n; i++)
		free(dp[i]);
	free(dp);

	return 0;

}
	