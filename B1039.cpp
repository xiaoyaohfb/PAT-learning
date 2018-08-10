#include <cstdio>
#include <cstring>
int main(){
  int HashTable[256] = {0};
  char a1[1010], a2[1010];
  scanf("%s", a1);
  scanf("%s", a2);
  int len1 = strlen(a1);
  int len2 = strlen(a2);
  for(int i = 0; i < len1; i++){
    HashTable[a1[i]]++;
  }
  int num = 0;
  bool flag = true;
  for(int i = 0; i < len2; i++){
    if(HashTable[a2[i]] == 0){
      flag = false;
      num++;
    }
    else HashTable[a2[i]]--;
  }
  if(flag == true) {
    printf("Yes %d", len1 - len2);
  }
  else printf("No %d", num);
}