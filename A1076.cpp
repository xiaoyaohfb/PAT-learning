#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct node{
  int v;
  int layer;
};
vector<node> vec[1010];
int k;
int BFS(int u) {
  queue<node> q;
  bool inq[1010] = {false};
  int count = 0;
  node start;
  start.v = u;
  start.layer = 0;
  inq[start.v] = true; 
  q.push(start);
  while (!q.empty()) {
    node front = q.front();
    q.pop();
    int w = front.v;
    for (int i = 0; i < vec[w].size(); i++) {
      node next = vec[w][i];
      next.layer = front.layer + 1;
      if (!inq[next.v]) {
        q.push(next);
        inq[next.v] = true;
        if (next.layer > 0 && next.layer <= k) count++;
      }
    }
  }
  return count;
}
int main(){
  int  n;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int num;
    scanf("%d", &num);
    for (int j = 0; j < num; j++) {
      int t;
      scanf("%d", &t);
      node temp;
      temp.v = i;
      vec[t].push_back(temp);
    }
  }
  int m, query;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &query);
    printf("%d\n", BFS(query));
  }
}