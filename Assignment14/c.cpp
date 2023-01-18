#include <bits/stdc++.h>
using namespace std;

struct word{
    string sWord;
    string oWord;
};

int main(){
 
    ifstream file("testdata.in");
    string check, line;
    int n, m;
    file >> n;
    word W[n];
    file.ignore();
    for (int i = 0; i < n; i++){
        getline(file, W[i].sWord, '#');
        getline(file, W[i].oWord);
    }
    file >> m;
    file.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(file, line);
        int start = 0;
        cout << "Case #" << i+1 << ":" << endl; 
        for (int j = 0; j < line.length(); j++)
        {
            if(line[j] == ' ' || j == line.length()-1){
                if(j == line.length()-1) j++;
                check = line.substr(start, j-start);
                start = j+1;
                for(int k = 0; k < n; k++){
                    if(check == W[k].sWord){
                        cout << W[k].oWord;
                        break;
                    }
                    if(k == n-1) cout << check;
                }
                if(j != line.length()) cout << " ";
            }
        }
        cout << endl;
    }
    
return 0;
}