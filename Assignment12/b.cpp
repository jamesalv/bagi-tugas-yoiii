#include <bits/stdc++.h>
using namespace std;

int jobonacci(int x){
    if(x == 0)
        return 0;
    else if (x % 2 == 1)
        return 1;
    else
        return jobonacci(x-1) + jobonacci(x-2);
}

int main(){
 
    int n;
    cin >> n;
    cout << jobonacci(n) << endl;
 
return 0;
}