#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, n, x, max, cnt;
    cin >> tc;

    for(int i = 0; i < tc; i++){
        cin >> n;
        max = -1;
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if(x > max){
                max = x;
                cnt = 1;
            } else if (x == max){
                cnt++;
            }
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
 
return 0;
}