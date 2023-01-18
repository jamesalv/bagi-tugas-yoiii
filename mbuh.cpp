#include <bits/stdc++.h>
using namespace std;

void ipt(int *x)
{
    for (int i = 0; i < 10; i++)
    {
        cin >> x[i];
    }
}

int maxVal(int y[])
{
    int max = y[0];
    for (int i = 0; i < 10; i++)
    {
        if (y[i] > max)
            max = y[i];
    }
    return max;
}

int minVal(int z[])
{
    int min = z[0];
    for (int i = 0; i < 10; i++)
    {
        if (z[i] < min)
            min = z[i];
    }
    return min;
}

void prt(int res[])
{    
    ipt(res);
    cout << "Numbers: ";
    for (int i = 0; i < 10; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    cout << "Maximum: " << maxVal(res) << endl;
    cout << "Minimum: " << minVal(res) << endl;
}

int main()
{
    int arr[10];
    prt(arr);
    return 0;
}