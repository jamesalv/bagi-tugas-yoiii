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

    char temp;
    int x1, y1;

    cin >> temp >> y1;
    x1 = temp - 'A' + 1;

    fill(9-y1, x1, 2);

    int mbuh = 8;
    for (int i = 1; i <= 8; i++)
    {
        cout << mbuh-- << "\t";
        for (int j = 1; j <= 8; j++)
        {
            cout << tile[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\tA B C D E F G H";

return 0;
}