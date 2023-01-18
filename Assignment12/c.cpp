#include <bits/stdc++.h>
using namespace std;


int main(){
 
    FILE *fptr;
    fptr = fopen("testdata.in", "r");
    int a, b;
    fscanf(fptr, "%d %d", &a, &b);
    cout << a + b << endl;
 
return 0;
}