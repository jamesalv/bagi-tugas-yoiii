#include <bits/stdc++.h>
using namespace std;

struct awikwok{
    string name;
    string plant;
};

int main(){
 
    ifstream file("testdata.in");
    awikwok a[100];
    int n, tc;
    string s;
    file >> n;
    getline(file, s);
    for(int i=0;i<n;i++){
        getline(file, s);
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '#'){
                a[i].name = s.substr(0, j);
                a[i].plant = s.substr(j+1, s.length());
                break;
            }
        }
    }
    file >> tc;
    getline(file, s);
    for(int i=0; i < tc; i++){
        bool flag = false;
        cout << "Case #" << i+1 << ": ";
        getline(file, s);
        for(int j = 0; j < n; j++){
            if(a[j].name == s){
                cout << a[j].plant << endl;
                flag = !flag;
                break;
            }
        }
        if(!flag){
            cout << "N/A" << endl;
        }
    }

    file.close();

return 0;
}