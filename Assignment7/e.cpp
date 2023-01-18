#include <bits/stdc++.h>
using namespace std;


int main(){
    
    // batas bawah = 0, batas atasnya = 100
    int x, max = -1, min = 101;
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < 10; i++)
    {
        //max
        if(arr[i] > max)
            max = arr[i];

        //min
        if(arr[i] < min)
            min = arr[i];
    }

    cout << max << ' ' << min << endl;
 
return 0;
}