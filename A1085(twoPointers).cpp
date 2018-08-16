#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int n;
  long long p;
  long long a[100010];
  scanf("%d %ld", &n, &p);
  for(int i = 0 ; i < n; i++){
    scanf("%ld", &a[i]);
  }
  sort(a, a + n);
  int i = 0, j = 0, count = 0;
  while(i < n && j < n){
    while(j < n && a[j] <= a[i] * p){
      count = max(count, j - i + 1);
      j++;
    }
    i++;
  }
  printf("%d", count);
}