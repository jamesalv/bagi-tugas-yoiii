#include<stdio.h>

int main(){
    long long tc, n, x, caseNum = 1;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        long long res = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld", &x);
            res += x;
        }
        printf("Case #%lld: %lld\n", caseNum++, res);
    }
    return 0;
}