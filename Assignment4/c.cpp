#include<stdio.h>

int main(){

    long long tc, n, m;
    long long res;

    scanf("%lld", &tc);
    for(int i = 1; i <= tc; i++){
        scanf("%lld %lld", &n, &m);
        res = n * m % 2;

        printf("Case #%d: ", i);
        if(res == 1)
            printf("Need more frogs\n");
        else
            printf("Party time!\n");
    }

    return 0;
}