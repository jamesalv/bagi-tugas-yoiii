#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int mat[n][m], transposed[m][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            transposed[i][j] = mat[j][i];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}