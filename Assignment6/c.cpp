#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int views[101], n, q, res;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> views[i];
    }

    cin >> q;
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        res = 0;
        for(int j = x-1; j < y; j++){
            res += views[j];
        }

        cout << "Case #" << i << ": " << res << endl;
    }
    
 
return 0;
}