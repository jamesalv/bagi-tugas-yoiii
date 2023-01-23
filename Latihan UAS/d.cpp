#include <bits/stdc++.h>
using namespace std;

int res;
void bubSort(vector<int> &V)
{
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = V.size() - 1; j > i; j--)
        {
            if (V[j] < V[j - 1])
            {
                swap(V[j], V[j - 1]);
                res++;
            }
        }
    }
}

int main()
{

    int tc, n, x;
    cin >> tc;
    res = 0;
    vector<int> c;
    for (int j = 0; j < tc; j++)
    {
        c.clear();
        cin >> n >> x;
        res = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            c.push_back(x);
        }
        bubSort(c);
        cout << "Case #" << j + 1 << ": " << res*x << endl;
    }
    return 0;
}