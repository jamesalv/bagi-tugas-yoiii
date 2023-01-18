#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int tc, len, breath;
    char x;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        fflush(stdin);
        cin >> len >> breath;
        bool death = false;
        int count = 0;
        int front = -1, back = -1;
        for(int j = 0; j < len; j++){
            cin >> x;
            if(x == '1'){
                if(front == -1)
                    front = j;
                back = j;
                count++;
            }

        }
        cout << front << " " << back << " " << count << endl;
        if(count == 0 || count == 1){
            if(len > breath)
                death = true;
        }
        else if(front >= breath || len - back > breath)
            death = true;

        cout << "Case #" << i+1 << ": ";
        if(death)
            cout << "Dead" << endl;
        else
            cout << "Alive" << endl;
    }
return 0;
}