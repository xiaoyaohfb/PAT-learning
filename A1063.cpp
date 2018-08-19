#include <set>
#include <cstdio>
using namespace std;
set<int> st[52];
void compare(int x, int y){
  int totalNum = st[y].size(), sameNum = 0;
  for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++){
    if(st[y].find(*it) != st[y].end()) sameNum++;
    else totalNum++;
  }
  printf("%.1f%%\n", sameNum * 100 / (float)totalNum);
}
int main(){
  int n, m, num, k, p, q;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &m);
    for(int j = 0; j < m; j++){
      scanf("%d", &num);
      st[i].insert(num);
    }
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d%d", &p, &q);
    compare(p, q);
  }
}