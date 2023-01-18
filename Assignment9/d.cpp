#include <bits/stdc++.h>
using namespace std;

bool solve(long long x, bool res){
    if(x == 1)  return res;
    else if(x % 2 == 0)
        return solve(x / 2, !res);
    else
        return solve(x * 3 + 1, !res);
}

int main(){
 
    long long tc, n;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        cout << "Case #" << i + 1 << ": ";
        if(solve(n, true)){
            cout << "Lili";
        }else{
            cout << "Jojo";
        }
        cout << endl;
    }
 
return 0;
}