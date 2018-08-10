#include <cstdio>
#include <cstring>
bool HashTable[256] = {false};
int main(){
  char b1[100010], b2[100010];
  scanf("%s", b1);
  scanf("%s", b2);
  int len1 = strlen(b1);
  int len2 = strlen(b2);
  int num = 0;
  for(int i = 0; i < len1; i++){
    if(b1[i] >= 'A' && b1[i] <= 'Z') b1[i] = b1[i] - 'A' + 'a';
    HashTable[b1[i]] = true;
  }
  for(int i = 0; i < len2; i++){
    if(b2[i] >= 'A' && b2[i] <= 'Z'){
      int low = b2[i] - 'A' + 'a';
      if(HashTable[low] != true && HashTable['+'] != true) printf("%c", b2[i]);
    }
    else if(HashTable[b2[i]] != true) printf("%c", b2[i]);
  }
  printf("\n");
}