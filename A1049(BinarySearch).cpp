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
  for (int i = 0; i < n - 1; i++){
    if(a[i] >= m){
      printf("No Solution");
      return 0;
    }
    int left = i + 1, right = n;
    while(left < right){
      int mid = left + (right - left) / 2;
      if(a[mid] >= (m - a[i])){
        right = mid;
      }
      else left = mid + 1;
    }
    if(a[right] == m - a[i]){
      printf("%d %d", a[i], a[right]);
      return 0;
    }
  }
  printf("No Solution");
  return 0;
}