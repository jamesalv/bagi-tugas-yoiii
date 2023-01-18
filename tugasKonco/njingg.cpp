#include <bits/stdc++.h>
using namespace std;

int main(){
 
    int ans = 0, n;
    cin >> n;
    for(int i = n+1; i > 0; i--){
        ans += i;
    }
    cout << ans << endl;
 
return 0;
}