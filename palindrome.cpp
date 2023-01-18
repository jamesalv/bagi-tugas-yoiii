#include<bits/stdc++.h>
using namespace std;

int main(){

    string S;
    getline(cin, S);

    for(int i = 0, j = S.length() - 1; i < S.length(); i++, j--){
        if(S[i] != S[j]){
            cout << "Bukan Palindrome" << endl;
            break;
        }

        if(i == S.length() - 1){
            cout << "Palindrome" << endl;
        }
    }
    return 0;
}