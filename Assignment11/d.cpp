#include <bits/stdc++.h>
using namespace std;

int jojonacci(int n, int x, int y){
    if (n == 0)
        return x;
    else if (n == 1)
        return y;
    else
        return jojonacci(n - 1, x, y) - jojonacci(n - 2, x, y);
}

int main(){
 
    int tc, x, y, n;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> n >> x >> y;
        cout << "Case #" << i + 1 << ": " << jojonacci(n, x, y) << endl;
    }
    
 
return 0;
}