#include <bits/stdc++.h>
using namespace std;

int b;

void rec(int x){
    if(x == b){cout << "YES" << endl; return;}
    if(x == 1){cout << "NO" << endl; return;}
    if(x % 2 == 0) rec(x / 2);
    else rec(x * 3 + 1);
}

int main(){
 
    int tc, a;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i + 1 << ": ";
        rec(a);
    }
    
 
return 0;
}