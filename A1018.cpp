#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 505;
const int INF = 1000000000;
struct node{
    int v, dis;
    node(int _v, int _dis) : v(_v), dis(_dis) {}
};
int OptValue = 1000000000;
vector<node> vec[maxn];
vector<int> pre[maxn];
vector<int> path, tempPath;
int cmax, n;
int d[maxn];
int weight[maxn];
bool visit[maxn] = {false};
int aneed = INF, aremain = INF;
void Dijkstra(int s){
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++) {
            if (!visit[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int j = 0; j < vec[u].size(); j++) {
            int v = vec[u][j].v;
            if (!visit[v]) {
                if (d[u] + vec[u][j].dis < d[v]) {
                    d[v] = d[u] + vec[u][j].dis;
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + vec[u][j].dis == d[v])
                    pre[v].push_back(u);
            }
        }
    }
}

void CalValue(int &need, int &remain){
    need = 0, remain = 0;
    for (int i = tempPath.size() - 1; i >= 0; i--) {
      int w = - weight[tempPath[i]] + cmax / 2;
      if (w < 0) remain = remain - w;
      else {
        if (remain > w) remain -= w;
        else {
          need += (w - remain);
          remain = 0;
        }
      }
    }
}
void DFS(int v) {
    if (v == 0) {
        int need, remain;
        CalValue(need, remain);
        if (need < aneed) {
          aneed = need;
          aremain = remain;
          path = tempPath;
        }
        else if (need == aneed) {
          if (aremain > remain) {
            aremain = remain;
            path = tempPath;
          }
        }
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
int main(){
    int m, end;
    scanf("%d%d%d%d", &cmax, &n, &end, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; i++) {
        int t1, t2, dis;
        scanf("%d%d%d", &t1, &t2, &dis);
        vec[t1].push_back(node(t2, dis));
        vec[t2].push_back(node(t1, dis));
    }
    Dijkstra(0);
    DFS(end);
    printf("%d 0", aneed);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("->%d", path[i]);
    }
    printf(" %d", aremain);
}