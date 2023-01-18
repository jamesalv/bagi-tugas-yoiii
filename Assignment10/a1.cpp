#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        long long n, k;
        cin >> n >> k;
        string arr;
        int count = 0;
        int front = -1, back = -1;
        bool death = false;

        cin >> arr;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == '1')
            {
                if (front == -1)
                {
                    front = j;
                }
                back = j;
                count++;
            }
        }
        // cout << front << " " << back << " " << count << endl;
        if ((count == 0 || count == 1) && n > k)
        {
            death = true;
        } else if (front >= k || n - back > k)
        {
            death = true;
        }

        cout << "Case #" << i + 1 << ": ";
        if (death)
        {
            cout << "Dead" << endl;
        } else
        {
            cout << "Alive" << endl;
        }
    }
    return 0;
}