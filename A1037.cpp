#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
  return a > b;
}
int main(){
  int nc[100010], np[100010];
  long long int sum = 0;
  int n, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &nc[i]);
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &np[i]);
  }
  sort(nc, nc + n, cmp);
  sort(np, np + m, cmp);
  for(int i = 0; i < m && i < n; i++){
    if(nc[i] > 0 && np[i] > 0){
      sum += nc[i] * np[i];
    }
    else break;
  }
  sort(nc, nc + n);
  sort(np, np + m);
  for(int i = 0; i < m && i < n; i++){
    if(nc[i] < 0 && np[i] < 0){
      sum += nc[i] * np[i];
    }
    else break;
  }
  printf("%d", sum);
}