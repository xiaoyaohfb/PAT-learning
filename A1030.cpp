#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 505;
const int INF = 100000000;
struct node{
  int v, dis;
};
vector<node> vec[maxn];
int n, s1, s2;
int cost[maxn][maxn];
int d[maxn];
vector<int>path, tempPath;
vector<int> pre[maxn];
int OptValue = INF;
bool visit[maxn] = {false};
void Dijkstra(int s){
  fill(d, d + maxn, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, MIN = INF;
    for (int j = 0; j < n; j++) {
      if (visit[j] == false && d[j] < MIN) {
        MIN = d[j];
        u = j;
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
int CalValue(){
  int value = 0;
  for (int i = tempPath.size() - 1; i > 0; i--) {
    int id = tempPath[i], nextId = tempPath[i-1];
    value += cost[id][nextId];
  }
  return value;
}
void DFS(int v){
  if (v == s1) {
    tempPath.push_back(v);
    int value = CalValue();
    if (value < OptValue) {
      OptValue = value;
      path = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  tempPath.push_back(v);
  for (int i = 0; i < pre[v].size(); i++) {
    DFS(pre[v][i]);
  }
  tempPath.pop_back();
}
int main(){
  int m;
  scanf("%d%d%d%d", &n, &m, &s1, &s2);
  for (int i = 0; i < m; i++) {
    int t1, t2, dis, cost1;
    scanf("%d%d%d%d", &t1, &t2, &dis, &cost1);
    node temp;
    cost[t1][t2] = cost1;
    cost[t2][t1] = cost1;
    temp.dis = dis;
    temp.v = t1;
    vec[t2].push_back(temp);
    temp.v = t2;
    vec[t1].push_back(temp);
  }
  Dijkstra(s1);
  DFS(s2);
  for(int i = path.size() - 1; i >= 0; i--) {
    printf("%d ", path[i]);
    if (i == 0) printf("%d %d", d[s2], OptValue);
  }
}