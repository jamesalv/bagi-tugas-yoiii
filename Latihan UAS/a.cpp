#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moveList = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool check(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7) return false;
    return true;
}
int N = 8;
int bfs(int xStart, int yStart, int xEnd, int yEnd){
    int distance[8][8];
    memset(distance, 0, sizeof(distance));
    queue<pair<int, int>> q;
    q.push({xStart, yStart});

    while (!q.empty())
    {
        int posX = q.front().first;
        int posY = q.front().second;
        q.pop();
        if(posX == xEnd && posY == yEnd)
            return distance[posX][posY];
        else{
            for(int i = 0; i < 8; i++){
                int newX = posX + moveList[i].first;
                int newY = posY + moveList[i].second;
                if(check(newX, newY) && distance[newX][newY] == 0){
                    distance[newX][newY] = distance[posX][posY] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
    return -1;
}

int main(){
 
    int tc, rowStart, rowEnd;
    char colStart, colEnd;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int res = -1;
        cin >> colStart >> rowStart;
        char test = getchar();
        cin >> colEnd >> rowEnd;
        res = bfs(colStart-'A', rowStart-1, colEnd-'A', rowEnd-1);
        cout << "Case #" << i + 1 << ": " << res << endl;
    }
    
 
return 0;
}