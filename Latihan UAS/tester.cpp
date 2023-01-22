#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

int bfs(int startX, int startY, int endX, int endY) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        if (x == endX && y == endY) return dist[x][y];

        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i], newY = y + dy[i];
            if (isValid(newX, newY) && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
    return -1;
}

int main() {
    int startX, startY, endX, endY;
    cout << "Enter the starting position of the knight (x y): ";
    cin >> startX >> startY;
    cout << "Enter the ending position of the knight (x y): ";
    cin >> endX >> endY;

    int minMoves = bfs(startX, startY, endX, endY);
    if (minMoves == -1) cout << "Invalid input or no solution exists." << endl;
    else cout << "Minimum number of moves: " << minMoves << endl;

    return 0;
}
