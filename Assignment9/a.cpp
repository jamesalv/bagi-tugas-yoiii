#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int n, m, q;
    int x, y, a;
    cin >> n >> m >> q;

    int arr[n][m];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < q; i++){
        cin >> x >> y >> a;
        arr[x][y] = a;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j];
            if(j != m-1) cout << " ";
        }
        cout << endl;
    }
 
return 0;
}