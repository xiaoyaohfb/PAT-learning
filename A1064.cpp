#include <cstdio>
#include <algorithm>
#include <queue>
const int maxn = 1010;
using namespace std;
int a[maxn], n, t[maxn], num = 0;
void InOrder(int root){
  if (root > n) return;
  InOrder(2 * root);
  a[root] = t[num++];
  InOrder(2 * root + 1);
}
void LevelOrder(int root){
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    printf("%d", a[front]);
    if (front != n) printf(" ");
    if (front * 2 <= n) q.push(front * 2);
    if (front * 2 + 1<= n) q.push(front * 2 + 1);
  }
}
int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  sort(t, t + n);
  InOrder(1);
  LevelOrder(1);
}