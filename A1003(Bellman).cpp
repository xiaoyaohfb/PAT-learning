#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
const int INF = 1000000000;
struct node{
  int v, dis;
  node (int _v, int _dis) : v(_v), dis(_dis) {}
};
vector<node> vec[501];
int weight[501];
int w[501] = {0};
int d[501];
int num[501] = {0};
set<int> pre[501];
void Bellman(int s){
  fill(d, d + 501, INF);
  w[s] = weight[s];
  d[s] = 0;
  num[s] = 1;
  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (int j = 0; j < vec[u].size(); j++) {
        int v = vec[u][j].v;
        if (d[v] > d[u] + vec[u][j].dis) {
          d[v] = d[u] + vec[u][j].dis;
          w[v] = w[u] + weight[v];
          num[v] = num[u];
          pre[v].clear();
          pre[v].insert(u);
        }
        else if (d[v] == d[u] + vec[u][j].dis) {
          if (w[v] < w[u] + weight[v])
            w[v] = w[u] + weight[v];
          pre[v].insert(u);
          num[v] = 0;
          for (auto it = pre[v].begin(); it !=pre[v].end(); it++) {
            num[v] += num[*it];
          }
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
    vec[t2].push_back(node(t1, dis));
    vec[t1].push_back(node(t2, dis));
  }
  Bellman(s1);
  printf("%d %d", num[s2], w[s2]);
}