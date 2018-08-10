#include <cstdio>
#include <cstring>
const char req[7] = {'P', 'A', 'T', 'e', 's', 't'};
int main(){
  int HashTable[128] = {0};
  char a[10010];
  scanf("%s", a);
  int len = strlen(a);
  for(int i = 0; i < len; i++){
    HashTable[a[i]]++;
  }
  while(true){
    int num = 0;
    for(int i = 0; i < 6; i++){
      if(HashTable[req[i]] != 0){
        printf("%c", req[i]);
        HashTable[req[i]]--;
      }
      else num++;
    }
    if(num == 6) break;
  }
}