#include <cstdio>
#include <map>
#include <cstdlib>
using namespace std;
struct Node{
  int data;
  int next;
}node[100010];
bool HashTable[1000010] = {false};
int main(){
  int s1, n, s2 = -100, p1, p2, address;
  bool flag = false;
  scanf("%d%d", &s1, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &address);
    scanf("%d%d", &node[address].data, &node[address].next);
  }
  HashTable[abs(node[s1].data)];
  int pre = s1;
  HashTable[abs(node[s1].data)] = true;
  for (p1 = node[s1].next; p1 != -1; p1 = node[p1].next) {
    if (HashTable[abs(node[p1].data)] == false) {
      HashTable[abs(node[p1].data)] = true;
      node[pre].next = p1;
      pre = p1;
    }
    else {
      if (s2 == -100) {
        s2 = p1;
        p2 = p1;
      }
      else {
        node[p2].next = p1;
        p2 = p1;
      }
    }
  }
  node[p2].next = -1;
  node[pre].next = -1;
  for (int p = s1; p != -1; p = node[p].next) {
    if (node[p].next != -1) printf("%05d %d %05d\n", p, node[p].data, node[p].next);
    else printf("%05d %d -1\n", p, node[p].data);
  }
  if(s2 != -100) {
    for (int p = s2; p != -1; p = node[p].next) {
      if (node[p].next != -1) printf("%05d %d %05d\n", p, node[p].data, node[p].next);
      else printf("%05d %d -1\n", p, node[p].data);
    }
  }
}