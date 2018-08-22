#include <cstdio>
struct Node{
  char c;
  int next;
  bool flag;
}node[100010];
int main(){
  int address1, address2, n, address, next;
  char data;
  scanf("%d%d%d", &address1, &address2, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %c %d", &address, &data, &next);
    node[address].c = data;
    node[address].next = next;
  }
  int p;
  for (p = address1; p != -1; p = node[p].next) {
    node[p].flag =true;
  }
  for (p = address2; p != -1; p = node[p].next) {
    if (node[p].flag == true) {
      printf("%05d", p);
      return 0;
    }
  }
  printf("-1");
}