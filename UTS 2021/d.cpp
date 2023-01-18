#include <bits/stdc++.h>
using namespace std;


int main(){
 
    // Chinese Remainder Theorem
    int a, b;
    cin >> a >> b;
    int num = ((a - 104)/105 + 1) * 105 + 104;
    
    while(num <= b){
        cout << num << endl;
        num += 105;
    }
    
 
return 0;
}