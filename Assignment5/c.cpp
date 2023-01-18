#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, a, b, c, cb;

    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> a >> b >> c;
        cb = a / 100 * b;

        if (cb < c)
            cout << "Case #" << i + 1 << ": " << cb << endl;
        else
            cout << "Case #" << i + 1 << ": " <<  c << endl;
    }
    
 
return 0;
}