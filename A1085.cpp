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
  int max = -1, num;
  for(int i = 0; i < n; i++){
    int left = i, right = n;
    while(left < right){
      int mid = (left + right) / 2;
      if(a[mid] > a[i] * p){
        right = mid;
      }
      else left = mid + 1;
    }
    num = left - i;
    if(num > max){
      max = num;
    }
  }
  printf("%d", max);
}