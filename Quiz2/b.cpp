#include <bits/stdc++.h>
using namespace std;

struct weapon{
    string name;
    int damage;
};

// void bubSort(weapon W[], int n){
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = 0; j < n-i-1; j++)
//         {
//             if(W[j].damage > W[j+1].damage){
//                 swap(W[j], W[j+1]);
//             }
//         }
//     }
// }

int main(){
 
    int T;
    cin >> T;
    weapon W[T];
    for (int i = 0; i < T; i++)
    {
        cin >> W[i].name >> W[i].damage;
    }
    
    // sort by damage
    sort(W, W+T, [](weapon a, weapon b){
        return a.damage < b.damage;
    });

    for (int i = 0; i < T; i++)
    {
        cout << W[i].name << " " << W[i].damage << endl;
    }
    
return 0;
}