#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int n;
    cin >> n;
    char arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = n-1; i >=0 ; i--)
    {
        for(int j = n-1; j >=0; j--){
            cout << arr[i][j];
        }
        cout << endl;
    }
    
    

 
return 0;
}