#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<int> vec[10010];
vector<int> ans;
set<int> s;
int num = 0,  maxheight = 0;
bool visit[10010] = {false};
int n, maxn = 0;
void DFS(int node, int height) {
  if (height > maxheight) {
    ans.clear();
    ans.push_back(node);
    maxheight = height;
  }
  else if (height == maxheight) ans.push_back(node);
  visit[node] = true;
  for (int i = 0; i < vec[node].size(); i++) {
    if (!visit[vec[node][i]]) 
      DFS(vec[node][i], height + 1);
  }
}
int main(){
  scanf("%d", &n);
  int n1;
  for (int i = 0; i < n - 1; i++) {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    vec[t2].push_back(t1);
    vec[t1].push_back(t2);
  }
  for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
      DFS(i, 1);
      if (i == 1) {
        if (ans.size() != 0) n1 = ans[0];
        for (int j = 0; j < ans.size(); j++) {
          s.insert(ans[j]);
        }
      }
      num++;
    }
  }
  if (num >= 2) printf("Error: %d components", num);
  else {
    ans.clear();
    maxheight = 0;
    fill(visit, visit + 10010, false);
    DFS(n1, 1);
    for (int i = 0; i < ans.size(); i++) {
      s.insert(ans[i]);
    }
    for (auto it = s.begin(); it != s.end(); it++) {
      printf("%d\n", *it);
    }
  }
}








