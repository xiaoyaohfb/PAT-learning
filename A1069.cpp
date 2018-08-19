#include <cstdio>
#include <algorithm>
using namespace std;
void to_array(int n, int num[]){
  for(int i = 3; i >= 0; i--){
    num[i] = n % 10;
    n /= 10;
  }
}
bool cmp(int a, int b){
  return a > b;
}
int to_number(int num[]){
  int ans = 0;
  for(int i = 0; i < 4; i++){
    ans = ans * 10 + num[i];
  }
  return ans;
}
int main(){
  int n, num[5], MIN, MAX;
  scanf("%d", &n);
  while(1){
    to_array(n, num);
    sort(num, num + 4);
    MIN = to_number(num);
    sort(num, num + 4, cmp);
    MAX = to_number(num);
    n = MAX - MIN;
    printf("%04d - %04d = %04d\n", MAX, MIN, n);
    if(n == 0 || n == 6174) break;
  }
}