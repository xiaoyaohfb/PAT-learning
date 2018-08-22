#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
  int address;
  int data;
  int next;
  int flag;
}node[maxn];
bool cmp(Node a, Node b){
  if (a.flag == -1 || b.flag == -1) {
    return a.flag > b.flag;
  }
  else return a.data < b.data;
}
int main(){
  int n, s1;
  for(int i = 0; i < maxn; i++) {
    node[i].flag = -1;
  }
  scanf("%d%d", &n, &s1);
  for (int i = 0; i < n; i++) {
    int address, data, next;
    scanf("%d%d%d", &address, &data, &next);
    node[address].address = address;
    node[address].data = data;
    node[address].next = next;
  }
  int count = 0, p;
  for (p = s1; p != -1; p = node[p].next) {
    count++;
    node[p].flag = 0;
  }
  if (count == 0) {
    printf("0 -1\n");
    return 0;
  }
  sort(node, node + maxn, cmp);
  printf("%d %05d\n", count, node[0].address);
  for (int i = 0; i < count - 1; i++) {
    printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
  }
  printf("%05d %d -1\n", node[count-1].address, node[count-1].data);
}