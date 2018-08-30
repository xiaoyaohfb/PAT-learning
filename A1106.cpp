#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct Node{
  int depth;
  vector<int> child;
}node[100010];
double p, r;
int minn = 9999999, count = 0;
void DFS(int root, int depth){
  node[root].depth = depth + 1;
  if (node[root].child.size() == 0) {
    if (node[root].depth < minn) {
      minn = node[root].depth;
      count = 1;
    }
    else if (node[root].depth == minn) {
      count++;
    }
    return;
  }
  for (int i = 0; i < node[root].child.size(); i++) {
    DFS(node[root].child[i], node[root].depth);
  }
}
int main(){
  int n;
  scanf("%d%lf%lf", &n, &p, &r);
  r = r /100;
  for (int i = 0; i < n; i++) {
    int m, num;
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      scanf("%d", &num);
      node[i].child.push_back(num);
    }
  }
  DFS(0, -1);
  printf("%.4f %d\n", p * pow(1 + r, minn), count);
}