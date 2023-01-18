#include <bits/stdc++.h>
using namespace std;

struct City{
    string name;
    double temperature;
    char metric;
    double scaled;
};

double convert(double temp){
    return (temp - 32.00) * 5.00/9.00;
}

bool compare (City a, City b){
    if(a.scaled == b.scaled)
        return a.name < b.name;
    else
        return a.scaled < b.scaled;
}

int main(){
 
    ifstream file("testdata.in");
    City a[101];
    string s;
    int x = 0;

    while(getline(file, s)){
        int pos, cnt = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#' && cnt == 0){
                a[x].name = s.substr(0, i);
                pos = i+1;
                cnt++;
            }
            else if(s[i] == '#' && cnt == 1){
                a[x].temperature = stod(s.substr(pos, i-pos));
            }
        }
        a[x].metric = s[s.length()-1];
        if(a[x].metric == 'F'){
            a[x].scaled = convert(a[x].temperature);
            // a[x].scaled = round(a[x].scaled * 100) / 100;
        } else {
            a[x].scaled = a[x].temperature;
        }

        x++;

    }
    sort(a, a+x, compare);
    cout.precision(2);
    for(int i = 0; i < x; i++){
        cout << a[i].name << " is " << fixed << a[i].temperature << defaultfloat << a[i].metric << endl;
    }
    file.close();
 
return 0;
}