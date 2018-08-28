#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
  int child[101];
  int weight;
  int k;
}node[101];
vector<int> temp;
int n, m, s;
void DFS(int root, int weight){
  if (weight > s) {
    return;
  }
  if (node[root].k == -1 && node[root].weight + weight == s) {
    int len = temp.size();
    for (int i = 0; i < len; i++) {
      printf("%d ", node[temp[i]].weight);
    }
    printf("%d\n", node[root].weight);
  }
  weight += node[root].weight;
  temp.push_back(root);
  for (int i = 0; i < node[root].k; i++) {
    DFS(node[root].child[i], weight);
  }
  temp.pop_back();
}
bool cmp(int a, int b) {
  return node[a].weight > node[b].weight;
}
int main(){
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &node[i].weight);
    node[i].k = -1;
  }
  for (int i = 0; i < m; i++) {
    int id, k;
    scanf("%d%d", &id, &k);
    node[id].k = k;
    for (int j = 0; j < k; j++) {
      scanf("%d", &node[id].child[j]);
    }
    sort(node[id].child, node[id].child + k, cmp);
  }
  DFS(0, 0);
}







