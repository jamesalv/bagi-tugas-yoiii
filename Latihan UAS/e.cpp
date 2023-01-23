#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int n;
    bool easy = true;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            easy = false;
            break;
        }
    }
    if(easy)
        cout << "easy" << endl;
    else
        cout << "not easy" << endl;
 
return 0;
}