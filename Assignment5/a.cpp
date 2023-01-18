#include <bits/stdc++.h>
using namespace std;


int main(){

    int tc, n, i;
    int a, b, c, d, sum;
    bool arr[10001];

    cin >> tc;
    for(int j = 0; j < tc; j++){
        memset(arr, 0, sizeof(arr));
        sum = 0;
        cin >> n >> a >> b >> c >> d;

        i = 0;
        while(i <= n){
            i += a;
            arr[i] = true;
        }

        i = 0;
        while(i <= n){
            i += b;
            arr[i] = true;
        }

        i = 0;
        while(i <= n){
            i += c;
            arr[i] = true;
        }

        i = 0;
        while(i <= n){
            i += d;
            arr[i] = true;
        }

        for(int i = 1; i <= n; i++){
            if(arr[i] == true){
                sum++;
            }
        }

        cout << "Case #" << j+1 << ": " << sum << endl;
    }
 
return 0;
}