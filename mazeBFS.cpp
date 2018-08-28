#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 100;
char maze[maxn][maxn];
bool isQ[maxn][maxn] = {false};
int n, m;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
struct Node{
    int x, y;
    int step;
}S, T, temp;
bool Judge(int x, int y){
    if (x >= n || x < 0 || y >= m || y < 0) return false;
    if (maze[x][y] == '*') return false;
    if(isQ[x][y] == true) return false;
    return true;
}
int BFS(){
    queue<Node> q;
    q.push(S);
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        if (top.x == T.x && top.y == T.y) return top.step;
        for (int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (Judge(newX, newY)) {
                temp.x = newX;
                temp.y = newY;
                temp.step = top.step + 1;
                q.push(temp);
                isQ[newX][newY] = true;
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            maze[i][j] = getchar();
        }
        maze[i][m] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    printf("%d\n", BFS());
}