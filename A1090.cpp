#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct Node{
  int depth;
  vector<int> child;
}node[100010];
double p, r;
void DFS(int root, int depth){
  node[root].depth = depth + 1;
  if (node[root].child.size() == 0) {
    return;
  }
  for (int i = 0; i < node[root].child.size(); i++) {
    DFS(node[root].child[i], node[root].depth);
  }
}
int main(){
  int n, root;
  scanf("%d%lf%lf", &n, &p, &r);
  r = r / 100;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    if (m != -1) node[m].child.push_back(i);
    else root = i;
  }
  DFS(root, -1);
  int maxn = 0, count = 0;
  for (int i = 0; i < n; i++) {
    if (node[i].depth > maxn) {
      maxn = node[i].depth;
      count = 1;
    }
    else if (node[i].depth == maxn) {
      count++;
    }
  }
  printf("%.2f %d\n", p * pow(1 + r, maxn), count);
}