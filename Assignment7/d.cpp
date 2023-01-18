#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, m;
    string S;

    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cin >> S;
        int len = S.length();

        cin >> m;
        for(int j = 0; j < m; j++){
            char a, b; 
            cin >> a >> b;
            for(int k = 0; k < len; k++){ //loop di stringnya 
                if(S[k] == a)
                    S[k] = b;
            }
        }

        printf("Case #%d: %s\n", i, S.c_str());
    }

return 0;
}