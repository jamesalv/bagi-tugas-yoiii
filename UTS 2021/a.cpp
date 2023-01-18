#include <bits/stdc++.h>
using namespace std;

bool palindrome(string S)
{
    for (int i = 0, j = S.length() - 1; i < S.length(); i++, j--)
    {
        if (S[i] != S[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string s1, s2;
    int n;

    cin >> n;
    getchar();
    while (n--)
    {
        s1.clear();
        s2.clear();
        getline(cin, s1);
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != ' ')
                s2 += tolower(s1[i]);
        }
        if (palindrome(s2))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}