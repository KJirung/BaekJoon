// https://www.acmicpc.net/problem/13305

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int* dist = (int*)malloc((N - 1) * sizeof(int));
    int* price = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N - 1; i++)
        scanf("%d", &dist[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &price[i]);

    long long total_cost = 0;
    int min_price = price[0]; // 첫 도시의 가격을 최소 가격으로 초기화

    for (int i = 0; i < N - 1; i++) {
        // 현재 도시의 가격과 최소 가격을 비교하여 더 작은 값을 최소 가격으로 갱신
        if (price[i] < min_price) {
            min_price = price[i];
        }
        // 현재 도시까지의 거리와 최소 가격을 곱해서 총 비용에 더함
        total_cost += (long long)dist[i] * min_price;
    }

    printf("%lld", total_cost);

    free(dist);
    free(price);

    return 0;
}
