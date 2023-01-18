#include <stdio.h>

int main(){
    int n, q, a, b, sum;
    int z[101];
    

    scanf("%d", &n);
    for(int i= 0; i < n; i++){
        scanf("%d", &z[i]);
    }

    scanf("%d", &q);
    for(int x = 1; x <= q; x++){
        scanf("%d %d", &a, &b);
        sum = 0;
        for(int i = a; i<=b; i++){
            sum += z[i-1];
        }
        
        printf("Case #%d: %d\n", x, sum);
    }

    return 0;
}