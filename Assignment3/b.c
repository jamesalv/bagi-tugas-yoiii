#include<stdio.h>

long long final(int n){
    if(n == 1)
        return 100;
    else{
        return final(n-1) + 50*(n-1) + 100 ;
    }
}

int main(){

    long long n, base, bonus, total;
    scanf("%lld", &n);
    total = final(n);

    printf("%lld\n", total);


    return 0;
}