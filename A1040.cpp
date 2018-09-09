#include <cstdio>
#include <cstring>
const int maxn = 1010;
int dp[maxn][maxn];
int main(){
  char S[maxn];
  int ans = 1;
  memset(dp, 0, sizeof(dp));
  fgets(S, maxn, stdin);
  int len = strlen(S);
  for (int i = 0; i < len; i++) {
    dp[i][i] = 1;
    if (i < len - 1) {
      if (S[i] == S[i + 1]) {
        dp[i][i + 1] = 1;
        ans = 2;
      }
    }
  }
  for (int L = 3; L <= len; L++) {
    for (int i = 0; i + L - 1 < len; i++) {
      int j = i + L - 1;
      if (S[i] == S[j] && dp[i + 1][j - 1] == 1) {
        dp[i][j] = 1;
        ans = L;
      }
    }
  }
  printf("%d\n", ans);
}