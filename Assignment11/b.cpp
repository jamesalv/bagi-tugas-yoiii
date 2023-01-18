#include <bits/stdc++.h>
using namespace std;
int main()
{

    int tc, x;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> x;
        int len = 1 + (x - 1) * 2;
        int start = len / 2, end = start;
        for (int j = 0; j < x; j++)
        {   
            // cout << j+1 << "\t";
            for (int k = 0; k < len; k++)
            {
                if (k >= start && k <= end)
                    cout << "*";
                else 
                    cout << " ";
            }
            start--;
            end++;
            cout << endl;
        }
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// int main() {

//     int space, rows;

//     cin >> rows;

//     for(int i = 1, k = 0; i <= rows; ++i, k = 0) {
//         for(space = 1; space <= rows-i; ++space) {
//             cout <<"  ";
//         }

//         while(k != 2*i-1) {
//             cout << "*";
//             ++k;
//         }
//         cout << endl;
//     }    
//     return 0;
// }
