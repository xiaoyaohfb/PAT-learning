#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node{
    int x, y, z;
}Node;
const int M = 1290, N = 130;
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
int matrix[1290][130][61];
bool isQ[1290][130][61] = {false};
int n, m, slice, T;
bool Judge(int x, int y, int z){
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= slice) return false;
    if (isQ[x][y][z] || matrix[x][y][z] == 0) return false;
    return true;
}
int BFS(int x, int y, int z){
    queue<node> q;
    int count = 0;
    Node.x = x, Node.y = y, Node.z = z;
    q.push(Node);
    isQ[x][y][z] = true;
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        count++;
        for(int i = 0; i < 6; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if (Judge(newX, newY, newZ)) {
                Node.x = newX;
                Node.y = newY;
                Node.z = newZ;
                q.push(Node);
                isQ[newX][newY][newZ] = true;
            }
        }
    }
    if(count >= T) return count;
    else return 0;
}

int main(){
    scanf("%d%d%d%d", &m, &n, &slice, &T);
    for (int z= 0; z < slice; z++) {
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                scanf("%d", &matrix[x][y][z]);
            }
        }
    }
    int ans = 0;
    for (int z= 0; z < slice; z++) {
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (matrix[x][y][z] == 1 && !isQ[x][y][z]) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

