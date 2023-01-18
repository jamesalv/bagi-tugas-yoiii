#include <bits/stdc++.h>
using namespace std;

long long res;

int solve(long long x){
    if(x == 1)return 1;
    else if (x % 2 != 0)
        return solve(x-1) + solve(x + 1);
    else
        return solve(x/2);

    return 0;
}

int main(){
 
    int tc;
    long long n;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        res = 0;
        cout << "Case #" << i+1 << ": " << solve(n) << endl;
    }
    
 
return 0;
}