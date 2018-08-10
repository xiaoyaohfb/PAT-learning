#include <cstdio>
#include <cstring>
int main(){
  int HashTable[30] = {0};
  char a[1010];
  fgets(a, sizeof(a), stdin);
  int len = strlen(a);
  for(int i = 0; i < len; i++){
    if(a[i] >= 'a' && a[i] <= 'z'){
      HashTable[a[i] - 'a']++;
    }
    else if(a[i] >= 'A' && a[i] <= 'Z'){
      HashTable[a[i] - 'A']++;
    }
  }
  int max = -1, flag;
  for(int i = 0; i < 30; i++){
    if(HashTable[i] > max) {
      max = HashTable[i];
      flag = i;
    }
  }
  printf("%c %d", flag + 'a', max);
}