#include <stack>
#include <cstdio>
using namespace std;
const int maxn = 10100;
int main(){
  int n, m, q;
  int arr[maxn];
  scanf("%d%d%d", &m, &n, &q);
  for (int i = 0; i < q; i++) {
    int cur = 0;
    stack<int> st;
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[j]);
    }
    for (int j = 1; j <= n; j++) {
      st.push(j);
      if (st.size() > m) break;
      while (!st.empty() && arr[cur] == st.top()) {
        st.pop();
        cur++;
      }
    }
    if(cur == n) printf("YES\n");
    else printf("NO\n");
  }
}