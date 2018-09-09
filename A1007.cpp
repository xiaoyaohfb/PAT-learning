#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int INF = -1000000000;
int d[maxn], a[maxn], first[maxn];
int MaxSub(int n){
    if (n == 0) return a[0];
    else {
        d[n] = max(MaxSub(n-1) + a[n], a[n]);
        if (d[n] == a[n]) {
          first[n] = n;
        }
        else first[n] = first[n - 1];
        return d[n];
    }
}
int main(){
    int n;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) flag = true;
    }
    if (!flag) {
      printf("0 %d %d", a[0], a[n - 1]);
      return 0;
    }
    d[0] = a[0];
    first[0] = 0;
    MaxSub(n-1);
    int m = INF;
    int flag1;
    for (int i = 0; i < n; i++) {
      if (d[i] > m) {
        m = d[i];
        flag1 = i;        
      }
    }
    printf("%d %d %d\n", m, a[first[flag1]], a[flag1]);
}

