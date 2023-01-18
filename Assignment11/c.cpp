#include <bits/stdc++.h>
using namespace std;

double cylinderSurface(int r, int h){
    return 2 * 3.14 * r * (r + h);
}

int main(){
 
    int t, r, h;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> r >> h;
        cout.precision(2);
        cout << "Case #" << i + 1 << ": " << fixed << cylinderSurface(r, h) << endl;
        resetiosflags(ios::fixed);
    }
 
return 0;
}