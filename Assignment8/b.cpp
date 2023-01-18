#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, counter;
    bool sudah[26];
    string S;
    
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> S;
        counter = 0;
        memset(sudah, false, sizeof(sudah));
        for (int j = 0; j < S.length(); j++)
        {
            if(sudah[S[j] - 'a'] == false){
                sudah[S[j] - 'a'] = true;
                counter++;
            }
        }

        cout << "Case #" << i+1 << ": ";
        if(counter % 2 == 0)
            cout <<  "Yay\n";
        else
            cout << "Ewwww\n"; 
    }
return 0;
}