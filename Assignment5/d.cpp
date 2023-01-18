#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int x, y, k;
    int res1 = -1, res2 = -2;

    cin >> x >> y >> k;

    if (x <= k)
        res1 = k - x;
    if (y >= k);
        res2 = y - k;

    if(res1 == res2)
        cout << res1 << endl;
    else
        cout << -1 << endl;
 
return 0;
}