#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, n, res;
    int arr[500][500];
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> n;
        memset(arr, 0, sizeof(arr));

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cin >> arr[j][k];
            }
        }

        cout << "Case #" << i << ": ";
        for(int j = 0; j < n; j++){
            res = 0;
            for(int k = 0; k < n; k++){
                res += arr[k][j];
            }
            cout << res;
            if(j != n-1)
                cout << " ";
            else
                cout << endl;
        }
    }
 
return 0;
}