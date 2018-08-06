#include <cstdio>
#include <cstring>
char ex[5][6] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
char ex1[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main(){
  char t[11];
  scanf("%s", t);
  int len = strlen(t);
  int left = 0, right = len - 1;
  if(t[0] == '-'){
    printf("Fu");
    left++;
  }
  while(left + 4 <= right) right -= 4;
  while(left < len){
    bool flag = false;
    bool haveP = false;
    while(left <= right){
      if(left > 0 && t[left] == '0'){
        flag = true;
      }
      else{
        if(flag == true){
          printf(" ling");
          flag = false;
        }
      if(left > 0)printf(" ");
      printf("%s", ex1[t[left]-'0']);
      haveP = true;
      if(left != right)printf(" %s", ex[right - left - 1]);
      }
      left++;
    }
    if(haveP == true && right != len -1)printf(" %s", ex[(len-right-1)/4+2]);
    right += 4;
  }
}