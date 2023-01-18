#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, n, A[200], res;
    bool isTrue[401];
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> n;
        res = 0;
        memset(isTrue, false, sizeof(isTrue));
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        
        for (int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++){
                isTrue[A[i] + A[j]] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if(isTrue[A[i]])
                res++;
        }
        
        cout << "Case #" << i+1 << ": " << res << endl;
    }
    
 
return 0;
}