#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct Node{
  double goods;
  vector<int> child;
}node[100010];
double p, r, sum = 0.0;
void DFS(int root, int depth){
  if (node[root].child.size() == 0) {
    sum += node[root].goods * pow(1 + r, depth);
    return;
  }
  for (int i = 0; i < node[root].child.size(); i++) {
    DFS(node[root].child[i], depth + 1);
  }
}
int main(){
  int n;
  scanf("%d%lf%lf", &n, &p, &r);
  r = r /100;
  for (int i = 0; i < n; i++) {
    int m, num;
    scanf("%d", &m);
    if (m == 0) {
      scanf("%d", &num);
      node[i].goods = num;
    }
    for (int j = 0; j < m; j++) {
      scanf("%d", &num);
      node[i].child.push_back(num);
    }
  }
  DFS(0, 0);
  printf("%.1f\n", p * sum);
}