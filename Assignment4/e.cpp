#include<stdio.h>

int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = n; i < n+m+1; i++){
        printf("%d\n", i);
    }
    return 0;
}