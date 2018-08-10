#include <cstdio>
#include <cstring>
int main(){
  int n;
  int a[100010], HashTable[10010];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    HashTable[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (HashTable[a[i]] == 1) {
      printf("%d", a[i]);
      return 0;
    }
  }
  printf("None");
}