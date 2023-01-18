#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tc, n, arr[100], sum, res1, res2;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        memset(arr, 0, sizeof(arr));
        cin >> n;
        res1 = 0;
        res2 = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = arr[j] ^ arr[k];
                int x = 0;
                while (sum > 0)
                {
                    if (sum % 2 == 1)
                        x++;

                    sum /= 2;
                }
                if (x >= 3)
                    res1++;
                else
                    res2++;
            }
        }
        cout << "Case #" << i + 1 << ": " << res1 << " " << res2 << endl;
    }

    return 0;
}