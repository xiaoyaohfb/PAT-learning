#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
const int INF = 1000000000;
struct node{
  int v, dis;
};
vector<node> vec[501];
bool visit[501] = {false};
int weight[501];
int w[501] = {0};
int d[501];
int num[501] = {0};
void Dijkstra(int s) {
  fill(d, d + 501, INF);
  d[s] = 0;
  w[s] = weight[s];
  num[s] = 1;
  for (int i = 0; i < n; i++) {
    int u = -1, min = INF;
    for (int j = 0; j < n; j++) {
      if (visit[j] == false && d[j] < min) {
        min = d[j];
        u = j;
      }
    }
    if (u == -1) return;
    visit[u] = true;
    for (int j = 0; j < vec[u].size(); j++) {
      int v = vec[u][j].v;
      if (visit[v] == false) {
        if (d[u] + vec[u][j].dis < d[v]) {
          d[v] = d[u] + vec[u][j].dis;
          w[v] = w[u] + weight[v];
          num[v] = num[u];
        }
        else if (d[u] + vec[u][j].dis == d[v]) {
          if (w[u] + weight[v] > w[v])
            w[v] = w[u] + weight[v];
          num[v] += num[u];
        }
      }
    }
  }
}
int main(){
  int m, s1, s2;
  scanf("%d%d%d%d", &n, &m, &s1, &s2);
  for (int i = 0; i < n; i++) {
    scanf("%d", &weight[i]);
  }
  for (int i = 0; i < m; i++) {
    int t1, t2, dis;
    scanf("%d%d%d", &t1, &t2, &dis);
    node temp;
    temp.v = t1;
    temp.dis= dis;
    vec[t2].push_back(temp);
    temp.v = t2;
    vec[t1].push_back(temp);
  }
  Dijkstra(s1);
  printf("%d %d", num[s2], w[s2]);
}