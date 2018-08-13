#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
  return a > b;
}
int main(){
  int n, a[110], t[110];
  bool HashTable[1100] = {false};
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    int temp = a[i];
    while (temp != 1){
      if (temp % 2 == 0){
        temp = temp / 2;
        HashTable[temp] = true;
      }
      else{
        temp = (3 * temp + 1) / 2;
        HashTable[temp] = true;
      }
    }
  }
  int num = 0;
  for (int i = 0; i < n; i++){
    if (HashTable[a[i]] == false){
      t[num++] = a[i];
    }
  }
  sort(t, t + num, cmp);
  for (int i = 0; i < num; i++){
    printf("%d", t[i]);
    if (i != num - 1) printf(" ");
  }
}