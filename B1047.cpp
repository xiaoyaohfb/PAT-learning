#include <cstdio>
#include <cstring>
int main(){
  int n, teamNum, Grade, Nonesense;
  int max = -1, flag = -1;
  int HashTable[10010] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d-%d %d", &teamNum, &Nonesense, &Grade);
    HashTable[teamNum] += Grade;
    if(HashTable[teamNum] > max){
      flag = teamNum;
      max = HashTable[teamNum];
    }
  }
  printf("%d %d", flag, max);
}