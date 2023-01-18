#include <bits/stdc++.h>
using namespace std;


int main(){
 
    string S;
    
    for(int j = 0; j < 2; j++){
        S.clear();
        getline(cin, S);

        // abcszs def
        int len = S.length();
        for(int i = 0; i < len; i++){
            if(S[i] == ' '){
                S.insert(i, "szs");
                len += 3;
                if(i == len-1)
                    break;
                else 
                    i += 4;
            }
        }
        cout << S << "szs" << endl;
    }
    return 0;
}