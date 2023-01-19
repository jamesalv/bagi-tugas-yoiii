#include <bits/stdc++.h>
using namespace std;

struct Player{
    string name;
    int score;
};

// binary search
int binSearch(Player P[], int n, string key){
    int l = 0, r = n-1, mid;
    while(l <= r){
        mid = (l+r)/2;
        if(P[mid].name == key){
            return mid;
        } else if (P[mid].name < key){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
 
    int T, M;
    string P1, P2;
    cin >> T;
    Player P[T];

    for (int i = 0; i < T; i++)
    {
        cin >> P[i].name >> P[i].score;
    }

    cin >> M;
    while(M--){
        cin >> P1 >> P2;
        int posP1, posP2, scP1, scP2;
        posP1 = binSearch(P, T, P1);
        posP2 = binSearch(P, T, P2);
        scP1 = P[posP1].score;
        scP2 = P[posP2].score;
        if(posP1 == -1 || posP2 == -1){
            cout << "not found" << endl;
        } else if (posP1 == posP2){
            cout << "not valid" << endl;
        }else{
            cout << abs(scP1 - scP2) << " " << abs(posP1 - posP2) << endl;
        }
    }
 
return 0;
}