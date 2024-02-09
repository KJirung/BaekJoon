// https://www.acmicpc.net/problem/2720

# include <stdio.h>

int main()
{
    int n, price;
    int quarter, dime, nickel, penny;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        price=0, quarter=0, dime=0, nickel=0, penny=0;
        scanf("%d",&price);

        quarter=price/25; price-=quarter*25;
        dime=price/10; price-=dime*10;
        nickel=price/5; price-=nickel*5;
        penny=price; price-=penny;

        printf("%d %d %d %d\n",quarter, dime, nickel, penny);
    }

    return 0;
}
