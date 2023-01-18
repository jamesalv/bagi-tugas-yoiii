#include<stdio.h>

int main(){
    
    int n, c, s, v, res = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &c, &s, &v);
        if(v < s)
            res++;   
    }
    printf("%d\n", res);

    return 0;
}