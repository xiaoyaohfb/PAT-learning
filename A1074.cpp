#include <cstdio>
struct Node{
  int data;
  int next;
}node[100010];
int main(){
  int s1, n, m, address, count = 0;
  scanf("%d%d%d", &s1, &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &address);
    scanf("%d%d", &node[address].data, &node[address].next);
  }
  for(int p = s1; p != -1; p = node[p].next) count++;
  int p = s1, pre = s1, next = node[p].next, allhead;
  int tail[100010];
  for (int i = 0; i < count / m; i++) {
    tail[i] = p;
    for (int j = 0; j < m ; j++) {
      next = node[p].next;
      if(j != 0) node[p].next = pre;
      pre = p;
      p = next;
    }
    if (i == 0) allhead = pre;
    else node[tail[i-1]].next = pre;
    if(i == count / m - 1) node[tail[i]].next = next;
  }
  for (int p = allhead; p != -1; p = node[p].next) {
    if (node[p].next != -1) printf("%05d %d %05d\n", p, node[p].data, node[p].next);
    else printf("%05d %d -1\n", p, node[p].data);
  }
}