#include <bits/stdc++.h>
using namespace std;

int main()
{

    int tc, n, m, q;
    int friends[50][50];
    //  
    bool rooms[50];
    // valuenya true = kamarnya nyala, value false = kamar mati
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        cin >> n >> m >> q; 
        // n = jumlah teman
        // m = jumlah kamar
        // q = jumlah teman yang datang

        // buat reset arraynya
        // memset(friends, 0, sizeof(friends));
        // memset(rooms, 0, sizeof(rooms));

        // reset yang friends
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                friends[i][j] = 0;
            }
        }

        // reset yang rooms
        for (int i = 0; i < 50; i++)
        {
            rooms[i] = false;
        }
        
        // Masukin input teman dan polanya
        // friends[teman nomor berapa][pola teman tersebut] , teman nomer 1 = index 0, dst, kamar pertama = index 0, dst
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> friends[j][k];
            }
        }

        for (int j = 0; j < q; j++)
        {
            int temp;
            cin >> temp;

            for (int k = 0; k < m; k++)
            {
                if (friends[temp-1][k] == 1) // temen no n = index ke n-1, temp-1 karena index dimulai dari 0 sedangkan di soal dari 1
                    rooms[k] = !rooms[k];
            }
        }

        cout << "Case #" << i << ":\n";
        for(int j = 0; j < m; j++)
        {
            if(rooms[j])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
