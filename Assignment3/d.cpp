#include <bits/stdc++.h>
using namespace std;

struct balok{
    char x;
    int urutan;
};

bool compare(balok a, balok b){
    return a.x < b.x;
}

int main(){

    balok B[3];
    scanf("%c %c %c", &B[0].x, &B[1].x, &B[2].x);
    B[0].urutan = 1;
    B[1].urutan = 2;
    B[2].urutan = 3;
    sort(B, B+3, compare);

    printf("%d %d %d\n", B[0].urutan, B[1].urutan, B[2].urutan);
 
    
 
return 0;
}