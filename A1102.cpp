#include <cstdio>
#include <queue>
using namespace std;
struct Node{
  int left;
  int right;
  bool flag;
}node[100];
int n;
int num1 = 0;
void LevelOrder(int root){
  queue<int> q;
  int num = 0;
  q.push(root);
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    printf("%d", front);
    num++;
    if (num != n) printf(" ");
    else printf("\n");
    if (node[front].left != -1) q.push(node[front].left);
    if (node[front].right != -1) q.push(node[front].right);
  }
}
void InOrder(int root) {
  if (node[root].left != -1) InOrder(node[root].left);
  printf("%d", root);
  num1++;
  if (num1 != n) printf(" ");
  if (node[root].right != -1) InOrder(node[root].right);
}
void BFS(int root) {
  //int num = 0;
  queue<int> q1;
  q1.push(root);
  while (!q1.empty()) {
    int front = q1.front();
    q1.pop();
    //num++;
    //if (num != n) printf(" ");
    //else printf("\n");
    if (node[front].left != -1) q1.push(node[front].left);
    if (node[front].right != -1) q1.push(node[front].right);
    int temp;
    temp = node[front].left;
    node[front].left = node[front].right;
    node[front].right = temp;
  }
}
int main(){
  char t1, t2;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%*c%c %c", &t1, &t2);
    if (t1 !='-') {
      int num = t1 - '0';
      node[i].left = num;
      node[num].flag = true;
    }
    else node[i].left = -1;
    if (t2 !='-') {
      int num = t2 - '0';
      node[i].right = num;
      node[num].flag = true;
    }
    else node[i].right = -1;
  }
  int root;
  for (int i = 0; i < n; i++) {
    if (node[i].flag == false) {
      root = i;
      break;
    }
  }
  BFS(root);
  LevelOrder(root);
  InOrder(root);
}









