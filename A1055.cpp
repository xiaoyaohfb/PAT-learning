#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct richman{
  char name[10];
  int age;
  int net;
}man[100010], valid[100010];
bool cmp(richman a, richman b){
  if(a.net != b.net) return a.net > b.net;
  else if(a.age != b.age) return a.age < b.age;
  else return strcmp(a.name, b.name) < 0;
}
int main(){
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%s %d %d", man[i].name, &man[i].age, &man[i].net);
  }
  sort(man, man + n, cmp);
  int validn = 0;
  int Age[201] = {0};
  for(int i = 0; i < n; i++){
    if(Age[man[i].age] < 100){
      Age[man[i].age]++;
      valid[validn++] = man[i];
    }
  }
  int m, amin, amax;
  for(int j = 0; j < k; j++){
    int num = 0;
    scanf("%d %d %d", &m, &amin, &amax);
    printf("Case #%d:\n", j + 1);
    for(int i = 0; i < validn; i++){
      if(num >= m) break;
      if(valid[i].age >= amin && valid[i].age <= amax){
        printf("%s %d %d\n", valid[i].name, valid[i].age, valid[i].net);
        num++;
      }
    }
    if(num == 0) printf("None\n");
  }
}








