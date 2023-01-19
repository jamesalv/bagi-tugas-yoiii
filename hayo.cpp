#include <bits/stdc++.h>
using namespace std;

struct Player{
    string name;
    int mmr;
};

bool compare(Player a, Player b){
    if(a.mmr == b.mmr){
        return a.name < b.name;
    } else 
        return a.mmr > b.mmr;
}

int main(){
 
    int n;
    cin >> n;
    Player P[n];

    for (int i = 0; i < n; i++)
    {
        cin >> P[i].name >> P[i].mmr;
    }

    sort(P, P+n, compare);
    
    for(int i = 0; i < n; i++){
        cout << P[i].name << " " << P[i].mmr << endl;
    }
return 0;
}