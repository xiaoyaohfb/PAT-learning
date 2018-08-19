#include <cstdio>
#include <algorithm>
const int maxn = 1000010;
const int INF = 0x7fffffff;
using namespace std;
int main(){
  int n, m;
  int a[maxn], b[maxn];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &b[i]);
  }
  a[n] = b[m] = INF;
  int mediapos = (n + m - 1) / 2;
  int i = 0, j = 0, count = 0;
  while(count < mediapos){
    if(a[i] < b[j]) {
      i++;
      count++;
    }
    else{
      j++;
      count++;
    }
  }
  if(a[i] < b[j]) printf("%d", a[i]);
  else printf("%d", b[j]);
}