#include <bits/stdc++.h>
using namespace std;


int main(){
 
    vector<string> S;
    string s;
    int x, t;

    //stop input when enter is pressed
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' || i == s.length()-1){
            S.push_back(s.substr(0, i+1));
            s = s.substr(i+1, s.length());
            i = 0;
        }
    }

    cin >> x;
    cin >> t;
    for(int i = 0; i < t; i++){
        cout << S[x];
        if(i != t-1) cout << " ";
    }
    cout << endl;
 
return 0;
}