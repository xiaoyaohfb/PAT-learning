#include <cstdio>
#include <queue>
#include <vector>
int HashTable[101] = {0};
using namespace std;
struct Node{
  int level;
  vector<int> child;
}node[101];
queue<int> q;
int sum = 0, maxn = 0;
void BFS(int root){
  node[root].level = 1;
  q.push(root);
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    HashTable[node[front].level]++;
    if (HashTable[node[front].level] > HashTable[maxn]) maxn = node[front].level;
    for (int i = 0; i < node[front].child.size(); i++) {
      int num = node[front].child[i];
      node[num].level = node[front].level + 1;
      q.push(num);
    }
  }
}
int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i ++) {
    int id, t1, t2;
    scanf("%d%d", &id, &t1);
    for (int j = 0; j < t1; j++) {
      scanf("%d", &t2);
      node[id].child.push_back(t2);
    }
  }
  BFS(1);
  printf("%d %d\n", HashTable[maxn], maxn);
}