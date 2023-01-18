#include <bits/stdc++.h>
using namespace std;

int fib(int f0, int f1, int n){
    if (n == 0)
        return f0;
    else if (n == 1)
        return f1;
    else
        return fib(f0, f1, n - 1) + fib(f0, f1, n - 2);
}

int main(){
 
    int f0, f1, n;
    cin >> f0 >> f1 >> n;
    cout << fib(f0, f1, n) << endl;
 
return 0;
}