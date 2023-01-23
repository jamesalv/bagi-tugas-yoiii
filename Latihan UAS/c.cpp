#include <bits/stdc++.h>
using namespace std;

struct due{
    string subject;
    int deadline;
};

bool compare(due d1, due d2){
    if(d1.deadline == d2.deadline)
        return d1.subject < d2.subject;
    
    return d1.deadline < d2.deadline;
}

int main(){
 
    int n;
    cin >> n;
    due D[n];

    for (int i = 0; i < n; i++)
    {
        cin >> D[i].subject >> D[i].deadline;
    }
    sort(D, D+n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << D[i].subject << endl;
    }
    
 
return 0;
}