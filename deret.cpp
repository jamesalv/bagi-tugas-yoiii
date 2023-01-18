#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, num;
    cin >> n;
    if (n % 2 == 0)
    {
        num = 2;
    }
    else
    {
        num = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << num << " ";
        num += 2;
    }
    cout << endl;

    return 0;
}