// https://www.acmicpc.net/problem/1026

#include <stdio.h>
#include <string.h>

void asc_a(int x[], int n);
void dec_b(int x[], int n);
int main()
{
    int a[51];
    int b[51];
    int swap_b[51];
    int num;
    int i;
    int s=0;

    scanf("%d",&num);

    for(i=0;i<num;i++)
        scanf("%d",&a[i]);
    for(i=0;i<num;i++)
        scanf("%d",&b[i]);
    memcpy(swap_b, b, sizeof(b));
    asc_a(a, num);
    dec_b(swap_b, num);

    for(i=0;i<num;i++)
        s+=a[i]*swap_b[i];


    printf("%d",s);

    return 0;

}
void asc_a(int x[], int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(x[i]<x[j]){
                x[i]^=x[j];
                x[j]^=x[i];
                x[i]^=x[j];
            }
        }
    }
}

void dec_b(int x[], int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(x[i]>x[j]){
                x[i]^=x[j];
                x[j]^=x[i];
                x[i]^=x[j];
            }
        }
    }
}
