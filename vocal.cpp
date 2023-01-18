#include<bits/stdc++.h>
using namespace std;

int main(){

    string S;
    char vocal[] = {'a', 'i', 'u', 'e', 'o', 'A', 'I', 'U', 'E', 'O'};

    getline(cin, S);
    for(int i = 0; i < S.length(); i++){
        for(int j = 0;  j < sizeof(vocal); j++){
            if(S[i] == vocal[j]){
                S[i] = '*';
                continue;
            }
        }
    }

    cout << S;

    return 0;
}