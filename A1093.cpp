#include <cstdio>
#include <cstring>
struct A{
  long long np;
  long long nt;
}a[100010];
int main(){
  char ch[100010];
  scanf("%s", ch);
  int len = strlen(ch);
  int count = 0;
  for(int i = 0; i < len; i++){
    if(ch[i] == 'P') count++;
    else if(ch[i] == 'A') {
      a[i].np = count; 
    }
  }
  count = 0;
  int sum = 0;
  for(int i = len - 1; i >= 0; i--){
    if(ch[i] == 'T') count++;
    if(ch[i] == 'A') {
      a[i].nt = count; 
      sum += a[i].np * a[i].nt;
      sum = sum % 1000000007;
    }
  }
  /*int sum = 0;
  for(int i = 0; i < num; i++){
    sum += a[i].np * a[i].nt) % 1000000007;
  }*/
  printf("%d", sum);
}