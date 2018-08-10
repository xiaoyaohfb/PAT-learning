#include <cstdio>
#include <cstring>
int main() {
  char a1[10010], a2[10010];
  bool HashTable[128] = {false};
  fgets(a1, sizeof(a1), stdin);
  fgets(a2, sizeof(a2), stdin);
  int len1 = strlen(a1);
  int len2 = strlen(a2);
  for (int i = 0; i < len2 - 1; i++){
    HashTable[a2[i]] = true;
  }
  for (int i = 0; i < len1 - 1; i++){
    if (HashTable[a1[i]] != true) printf("%c", a1[i]);
  }
}