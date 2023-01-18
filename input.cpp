#include <bits/stdc++.h>
using namespace std;


int main(){
 
    FILE *fp;
    long long d, m, y, yAge, mAge, dAge;

    fp = fopen("birthDate.txt", "r");
    if(fp == NULL){
        printf("File not found\n");
        return 0;
    }
    while(!feof(fp)){
        fscanf(fp, "%d/%d/%d", &d, &m, &y);
        // Calculate age from 19/12/2022
        yAge = 122 - y;
        mAge = 12 - m;
        dAge = 19 - d;

        if(dAge < 0){
            mAge--;
            dAge += 30;
        }
        if(mAge < 0){
            yAge--;
            mAge += 12;
        }
        printf("Age: %d years %d months %d days\n", yAge, mAge, dAge);
    }
 
return 0;
}