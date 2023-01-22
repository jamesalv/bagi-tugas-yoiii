#include <bits/stdc++.h>
using namespace std;

int res;
char arr[102][102];

vector<pair<int, int>> moveList = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(int x, int y){
    for(int i = 0; i < 4; i++){
        int newX = x + moveList[i].first, newY = y + moveList[i].second;
        if(arr[newX][newY] == '.'){
            res++;
            arr[newX][newY] = '!';
            solve(newX, newY);
        }
    }
}

int main(){
 
    int tc, n, m, rowStart, colStart;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        res = 0;
        cin >> n >> m;
        memset(arr, '#', sizeof(arr));
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                cin >> arr[j][k];
                if(arr[j][k] == 'S'){
                    rowStart = j;
                    colStart = k;
                }
            }
        }
        solve(rowStart, colStart);
        cout << "Case #" << i+1 << ": " << res << endl;
    }
    
 
return 0;
}