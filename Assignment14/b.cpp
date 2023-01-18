#include <bits/stdc++.h>
using namespace std;

char convertNum(char x){
    if(x == '0') return 'O';
    if(x == '1') return 'I';
    if(x == '3') return 'E';
    if(x == '4') return 'A';
    if(x == '5') return 'S';
    if(x == '6') return 'G';
    if(x == '7') return 'T';
    if(x == '8') return 'B';

    return x;
}

int main(){
 
    ifstream file("testdata.in");
    string S;
    int tc, k;
    file >> tc;
    getline(file, S);
    int x = 1;
    while(tc--){
        file >> k;
        getline(file, S);
        getline(file, S);
        for(int i = 0; i < S.length(); i++){
            if(S[i] >= '0' && S[i] <= '9'){
                S[i] = convertNum(S[i]);
            }
            if (S[i] != ' '){
                S[i] = S[i]-k;
                if(S[i] < 'A')
                    S[i] = S[i] + 26;
            }
        }
        cout << "Case #" << x++ << ": " << S << endl;
    }
    file.close();
return 0;
}