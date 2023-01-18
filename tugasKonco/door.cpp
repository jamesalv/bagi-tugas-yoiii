#include <bits/stdc++.h>
using namespace std;

int main()
{

    int TC;
    int n, m;
    bool kamar[10005];

    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        cin >> n >> m;
        memset(kamar, true, sizeof(kamar)); // buka = true, tutup = false;
        while (m--)
        {
            int temp, x;
            cin >> temp;
            x = temp;
            while (temp <= n)
            {
                kamar[temp] = !kamar[temp];
                temp += x;
            }
        }
        bool flag = false;
        cout << "Case #" << i + 1 << ": ";
        for (int j = 1; j <= n; j++)
        {
            if (kamar[j])
            {
                cout << j;
                if (j != n)
                    cout << " ";
                flag = true;
            }
        }
        if(!flag)
            cout << "No room left!";
        cout << endl;
    }
    return 0;
}
