#include <bits/stdc++.h>
using namespace std;


int main(){
 
    long long tc, n, m, minVal;

    cin >> tc;

    for(int i = 1; i <= tc; i++){

        minVal = 1000005;
        cin >> n >> m;
        while(n--){
            long long temp;
            cin >> temp;
            minVal = min(minVal, temp);
        }

        cout << "Case #" << i << ": " << m / minVal << endl;
    }
 
return 0;
}