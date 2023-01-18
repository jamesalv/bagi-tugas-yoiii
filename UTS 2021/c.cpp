#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tc, p, k;
    int pass[100], key[100], encrypted[100];
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> p >> k;
        memset(encrypted, 0, sizeof(encrypted));
        memset(key, 0, sizeof(key));
        memset(pass, 0, sizeof(pass));
        for (int i = 0; i < p; i++)
            cin >> pass[i];
        for (int i = 0; i < k; i++)
            cin >> key[i];


        for (int i = 0; i <= p - k; i++)
        {
            int x = i;
            for (int j = 0; j < k; j++)
            {
                encrypted[i] += pass[x] ^ key[j];
                x++;
            }
        }

        for(int i = 0; i <= p-k; i++){
            cout << encrypted[i];
            if(i != p-k)
                cout << " ";
        }
        cout << endl;
    }


    return 0;
}