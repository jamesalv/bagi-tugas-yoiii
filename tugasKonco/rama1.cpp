#include <bits/stdc++.h>
using namespace std;

long long dp[500];

long long factorial(int n){
    if(dp[n] != 0) return dp[n];
    else {
        if(n==0) return dp[0];
        else{
            dp[n] = n*factorial(n-1);
        }
    }
    return dp[n];
}

long long combination(int n, int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
    int r;
    cin >> r;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    cout << combination(3+r-1, r) << endl;
return 0;
}