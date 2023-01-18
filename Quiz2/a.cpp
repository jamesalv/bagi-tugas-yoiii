#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int m, n;
    cin >> m;
    long long arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    cin >> n;
    while(n--){
        int x, count = 0;
        cin >> x;
        for (int i = 0; i < m; i++)
        {
            if(arr[i] > x){
                count++;
            }
        }
        cout << count << endl;
    }
    
 
return 0;
}