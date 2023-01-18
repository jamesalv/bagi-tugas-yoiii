#include <bits/stdc++.h>
using namespace std;


int main(){
 
    long long N, x, sum = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x;
        sum += x;
    }
    
    cout << sum << endl;

return 0;
}