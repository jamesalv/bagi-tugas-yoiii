#include <bits/stdc++.h>
using namespace std;


int main(){
 
    string S, sBack;
    bool valid = true;
    cin >> S;
    for(int i = S.length()-1; i >= 0; i--){
        sBack += S[i];
    }

    for(int i = 0; i < S.length(); i++){
        if(S[i] == '_'){
            if(sBack[i] == '_')
                valid = false;
        } else {
            if(sBack[i] != S[i] && sBack[i] != '_')
                valid = false;
        }
    }

    if(valid) cout << "Yes" << endl;
    else cout << "No" << endl;

return 0;
}