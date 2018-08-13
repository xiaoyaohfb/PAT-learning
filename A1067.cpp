#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int n, a[100010], flag;
  scanf("%d", &n);
  int left = n - 1;
  for(int i = 0; i < n; i++){
    int num1;
    scanf("%d", &num1);
    a[num1] = i;
    if(i == num1 && num1 != 0) left--; 
  }
  int num = 0, k = 1;
  while(left > 0){
    if(a[0] == 0){
      while(k < n){
        if(a[k] != k){
          swap(a[0], a[k]);
          num++;
          break;
        }
        k++;
      }
    }
    while(a[0] != 0){
      swap(a[0], a[a[0]]);
      num++;
      left--;
    }
  }
  printf("%d", num);
}