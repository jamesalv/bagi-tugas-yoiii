#include <bits/stdc++.h>
using namespace std;

struct student{
    string ID, name;
};

bool compare(student a, student b){
    return a.ID < b.ID;
}

int main(){
 
    ifstream file("testdata.in");
    student S[1000];
    string str;

    int n;
    file >> n;
    getline(file, str);
    for(int i = 0; i < n; i++){
        file >> S[i].ID >> S[i].name;
    }

    sort(S, S+n, compare);
    
    for(int i = 0; i < n; i++){
        cout << S[i].ID << " " << S[i].name << endl;
    }
    file.close();
return 0;
}