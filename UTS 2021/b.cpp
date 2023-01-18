#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, n;
    int nums[11];
    cin >> tc;

    while(tc--){
        memset(nums, 0, sizeof(nums));
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int minDist = 10000;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(abs(nums[i] - nums[j]) < minDist)
                    minDist = abs(nums[i] - nums[j]);
            }
        }
        cout << minDist << endl;
    }
 
return 0;
}