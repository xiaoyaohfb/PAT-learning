#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int maxv = 110;
int w[maxn], dp[maxv] = {0};
bool cmp(int a, int b){
  return a > b;
}
bool choice[maxn][maxv], flag[maxn];
int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  sort(w + 1, w + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int v = m; v >= w[i]; v--) {
      if (dp[v] <= dp[v - w[i]] + w[i]) {
        dp[v] = dp[v - w[i]] + w[i];
        choice[i][v] = 1;
      }
      else choice[i][v] = 0;
    }
  }
  if (dp[m] != m) printf("No Solution\n");
  else {
    int k = n, v = m, num = 0;
    while(k >= 0) {
      if (choice[k][v] == 1) {
        flag[k] = true;
        v = v - w[k];
        num++;
      }
      else flag[k] = false;
      k--;
    }
    for (int i = n; i >= 1; i--) {
      if (flag[i] == true){
        printf("%d", w[i]);
        num--;
        if (num > 0) printf(" ");
      }
    }
  }
}