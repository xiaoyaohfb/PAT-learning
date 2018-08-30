#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
  int data;
  int left, right;
}node[101];
int t[101], num = 0, n;
void InOrder(int root) {
  if (node[root].left != -1) InOrder(node[root].left);
  node[root].data = t[num++];
  if (node[root].right != -1) InOrder(node[root].right);
}
void LevelOrder(int root) {
  num = 0;
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    printf("%d", node[front].data);
    num++;
    if (num != n) printf(" ");
    if (node[front].left != -1) q.push(node[front].left);
    if (node[front].right != -1) q.push(node[front].right);
  }
}
int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &node[i].left, &node[i].right);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t + n);
  InOrder(0);
  LevelOrder(0);
}