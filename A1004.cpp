#include <cstdio>
#include <vector>
using namespace std;
int HashTable[10100] = {0};
int maxn = -1;
struct Node{
  vector<int> child;
  int depth;
}node[101];
void DFS(int root, int depth) {
  node[root].depth = depth + 1;
  if (node[root].child.size() == 0) {
    HashTable[node[root].depth]++;
    if (node[root].depth > maxn) maxn = node[root].depth;
  }
  for (int i = 0; i < node[root].child.size(); i++) {
    DFS(node[root].child[i], node[root].depth);
  }
}
int main(){
  int n, m;
  scanf("%d", &n);
  if (n == 0) {
    printf("\n");
    return 0;
  }
  scanf("%d", &m);
  int id, num, temp;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &id, &num);
    for (int j = 0; j < num; j++) {
      scanf("%d", &temp);
      node[id].child.push_back(temp);
    }
  }
  DFS(1, 0);
  for (int i = 1; i <= maxn; i++) {
    printf("%d", HashTable[i]);
    if (i != maxn) printf(" ");
  }
}