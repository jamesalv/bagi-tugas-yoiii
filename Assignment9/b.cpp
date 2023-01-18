#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int N;
    cin >> N;
    int arr[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
        
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j];
            if(j != N-1) cout << " ";
        }
        cout << endl;
    }
 
return 0;
}