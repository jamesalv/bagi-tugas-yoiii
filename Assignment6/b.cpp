#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main(){
 
    long long tc, n , x, res, f, c;

    cin >> tc;
    res = 999999999;
    for(int i = 1; i <= tc; i++){
        cin >> n >> x;
        f = (x-1) / 2 + (x-1) % 2;
        if(n % 2 != 0){
            c = (n-x) / 2;
        } else {
            c = (n-x) / 2 + (n-x) % 2;
        }

        res = min(c, f);
        if(f < res)
            res = f;
        if(c < res)
            res = c;

        cout << "Case #" << i << ": " << res << endl;
    }
 
return 0;
}