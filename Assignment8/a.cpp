#include <bits/stdc++.h>
using namespace std;

int times;

int solve(int n){
    if(n % 3 == 0 && n != 0)
        times++;

    if(n==0) return 1;
    else if(n == 1) return 2;
    else if(n % 5 == 0)
        return n*2;
    else
        return solve(n-1) + n + solve(n-2) + n-2;
}


int main(){
 
    int tc, n;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        times = 0;
        cout << "Case #" << i+1 << ": " << solve(n) << " "<< times << endl;
    }
    
 
return 0;
}