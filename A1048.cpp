#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;  
int HashTable[maxn];
int main(){
  int n, m, temp;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++){
    scanf("%d", &temp);
    ++HashTable[temp];
  }
  for (int i = 0; i < maxn; i++){
    if (HashTable[i] && HashTable[m - i]){
      if (i == m - i && HashTable[i] <= 1){
        continue;
      }
      printf("%d %d\n", i, m - i);
      return 0;
    }
  }
  printf("No Solution\n");
  return 0;
}