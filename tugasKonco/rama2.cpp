#include <bits/stdc++.h>
using namespace std;

int tile[9][9];
bool sudahIsi[9][9];

void fill(int x, int y, int n)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8 && n != 0 && !sudahIsi[x][y])
    {
        tile[x][y]++;
        sudahIsi[x][y] = true;
        fill(x + 2, y + 1, n - 1);
        fill(x + 2, y - 1, n - 1);
        fill(x - 2, y + 1, n - 1);
        fill(x - 2, y - 1, n - 1);
        fill(x + 1, y + 2, n - 1);
        fill(x + 1, y - 2, n - 1);
        fill(x - 1, y + 2, n - 1);
        fill(x - 1, y - 2, n - 1);
    }
}

int main()
{

    int tc, n, y1, y2;
    char x1, x2;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        memset(tile, 0, sizeof(tile));
        fflush(stdin);
        bool ans = false;
        int temp;
        cin >> n;
        cin >> x1 >> y1;
        getchar();
        cin >> x2 >> y2;
        temp = x1 - 'A' + 1;
        memset(sudahIsi, 0, sizeof(sudahIsi));
        fill(9 - y1, temp, n + 1);
        temp = x2 - 'A' + 1;
        memset(sudahIsi, 0, sizeof(sudahIsi));
        fill(9 - y2, temp, n + 1);
        for (int j = 1; j <= 8; j++)
        {
            for (int k = 1; k <= 8; k++)
            {
                if (tile[j][k] >= 2)
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
                break;
        }

        cout << "Case #" << i + 1 << ": ";
        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
        //     int mbuh = 8;
        //     for(int i = 1; i <= 8; i++){
        //         cout << mbuh-- << "\t";
        //         for (int j = 1; j < 8; j++)
        //         {
        //             cout << tile[i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << "\n\tA B C D E F G H";
        // }

    }
    return 0;

}