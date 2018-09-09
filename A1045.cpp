#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 201;
const int N = 10010;
int priority[maxn]= {0};
int dp[N] = {0};
int A[N];
int main(){
  int n, m, k;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int color;
    scanf("%d", &color);
    priority[color] = i;
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &A[i]);
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    if (priority[A[i]] == 0) continue;
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (priority[A[i]] >= priority[A[j]] && dp[j] + 1 > dp[i])
        dp[i] = dp[j] + 1;
    }
    ans = max(ans, dp[i]);
  }
  printf("%d", ans);
}