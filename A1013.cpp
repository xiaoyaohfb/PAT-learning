#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> vec[1010];
int n;
int BFS(int query) {
  int num = 0;
  bool vis[1010] = {false};
  vis[query] = true;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      num++;
      queue<int> q;
      q.push(i);
      vis[i] = true;
      while(!q.empty()) {
        int front = q.front();
        q.pop();
        for (int j = 0; j < vec[front].size(); j++) {
          if (!vis[vec[front][j]]) {
            q.push(vec[front][j]);
            vis[vec[front][j]] = true;
          }
        }
      }
    }
  }
  return num - 1;
}

int main(){
  int m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int t1, t2;
    scanf("%d %d", &t1, &t2);
    vec[t1].push_back(t2);
    vec[t2].push_back(t1);
  }
  int query;
  for (int i = 0; i < k; i++) {
    scanf("%d", &query);
    printf("%d\n", BFS(query));
  }
}