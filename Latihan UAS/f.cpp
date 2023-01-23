#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    ifstream testCase("testdata.in");
    int perimeter, area;
    vector<int> ice;
    int tc;
    int n;
    testCase >> tc;
    for (int i = 0; i < tc; i++)
    {
        testCase >> n;
        perimeter = 0; area = 0;
        ice.clear();
        ice.push_back(0);
        for (int j = 1; j <= n; j++)
        {
            int x;
            testCase >> x;
            area += x;
            ice.push_back(x);
        }
        ice.push_back(0);

        for(int j = 1; j <= n; j++){
            perimeter += ice[j] * 2 + 2;

            if(ice[j-1] < ice[j])
                perimeter -= ice[j-1];
            else
                perimeter -= ice[j];

            if(ice[j+1] < ice[j])
                perimeter -= ice[j+1];
            else
                perimeter -= ice[j];
        }

        cout << "Case #" << i + 1 << ": " << perimeter * 2 << " " << area * 4 << endl;
    }
    testCase.close();

    return 0;
}