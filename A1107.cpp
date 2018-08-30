#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
  return a > b;
}
int a[1010], b[1010] = {0};
int FindFather(int x) {
  if (x == a[x]) return x;
  else {
    int F = FindFather(a[x]);
    a[x] = F;
    return F;
  }
}
void Union(int x, int y){
  int faA = FindFather(x);
  int faB = FindFather(y);
  if (faB != faA) a[faA] = faB;
}
int main(){
  int n, HashMap[1010] = {0};
  scanf("%d", &n);
  for (int i = 1; i < 1001; i++) {
    a[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    int k, pre;
    scanf("%d:", &k);
    for (int j = 0; j < k; j++) {
      int temp;
      scanf("%d", &temp);
      if (j == 0) {
        a[temp] = FindFather(temp);
        b[i] = temp;
      }
      else {
        Union(pre, temp);
      }
      pre = temp;
    }
  }
  for (int i = 1; i <= n; i++) {
    HashMap[FindFather(b[i])]++;
  }
  sort(HashMap, HashMap + 1001, cmp);
  int mark;
  for (int i = 0; i < 1001; i++) {
    if (HashMap[i] == 0) {
      mark = i;
      break;
    }
  }
  printf("%d\n", mark);
  for (int i = 0; i < mark; i++) {
    printf("%d", HashMap[i]);
    if (i != mark - 1) printf(" ");
  }
}







