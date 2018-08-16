#include <cstring>
#include <cstdio>
int get_pro(char *n, int radix){
  int sum;
  int len = strlen(n), product = 1;
  for(int i = len - 1; i >= 0; i--){
    if(n[i] <= '9' && n[i] >= '1') {
      sum += (n[i] - '0') * product;
      product = product * radix;
    }
    else{
      sum += (n[i] - 'a' + 10) * product;
      product = product * radix;
    }
  }
  return sum;
}
int main(){
    char n[3] = {"10"};
    printf("%d",get_pro(n, 2));
}