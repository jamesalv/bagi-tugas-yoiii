#include <bits/stdc++.h>
using namespace std;

bool check(string S)
{
    int dots = 0, nums = 0;
    // Huruf pertama dan terakhir pasti angka
    if (S[0] == '.' || S[S.length() - 1] == '.')
        return false;
    else
    {
        for (int i = 0; i < S.length(); i++)
        {
            // Cek apakah dia titik, kalau dia titik apakah karakter selanjutnya berupa angka?
            // Kalau iya berarti tambah jumlah titik, kalau bukan berarti IP tsb tidak valid
            if (S[i] == '.' && S[i + 1] >= '0' && S[i + 1] <= '9')
            {
                dots++;
            }
            // Apakah karakter berupa angka?
            else if (S[i] >= '0' && S[i] <= '9')
            {
                // Kalau iya, apakah karakter selanjutnya berupa titik atau akhir input?
                // Kalau iya tambah jumlah angka, kalau tidak lanjutkan loopnya
                if(S[i + 1] == '.' || S[i + 1] == '\0')
                    nums++;
            }
            else
                return false;
        }
    }

    // IP Valid hanya jika jumlah titik ada 5, jumlah angka ada 6
    if (dots == 5 && nums == 6)
        return true;
    else
        return false;
}

int main()
{

    int tc;
    string IP;
    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        cin >> IP;
        cout << "Case #" << i << ": ";
        if (check(IP))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}