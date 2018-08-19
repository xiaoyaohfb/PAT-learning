#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
  int n, m, a[100010];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int i = 0, j = n - 1;
  while(true){
    if(i == j){
      printf("No Solution");
      break;
    }
    if(a[i] + a[j] == m) {
      printf("%d %d", a[i] ,a[j]);
      break;
    }
    else if(a[i] + a[j] < m) i++;
    else j--;
  }
}