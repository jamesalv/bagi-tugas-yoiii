#include <bits/stdc++.h>
using namespace std;

int cnt;

int fibCount(int n){
    cnt++;
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibCount(n-1) + fibCount(n-2);
}

int main(){
 
    int tc, n;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        cnt = 0;
        fibCount(n);
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
    
 
return 0;
}