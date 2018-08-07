#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
  char id[10];
  int de, cai, sum;
  int type;
}stu[100010];
bool cmp(Student a, Student b){
  if(a.type != b.type) return a.type < b.type;
  else if(a.sum != b.type) return a.sum > b.sum;
  else if(a.de != b.de) return a.de > b.de;
  else return strcmp(a.id, b.id) < 0;
}
int main(){
  int n, L, H;
  scanf("%d%d%d", &n, &L, &H);
  int m = n;
  for(int i = 0; i < n; i++){
    scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
    stu[i].sum = stu[i].de + stu[i].cai;
    if(stu[i].de < L || stu[i].cai < L){
      stu[i].type = 5;
      m--;
    }
    else if(stu[i].de >= H && stu[i].cai >= H)stu[i].type = 1;
    else if(stu[i].de >= H && stu[i].cai < H) stu[i].type = 2;
    else if(stu[i].de >= stu[i].cai) stu[i].type = 3;
    else stu[i].type = 4;
  }
  sort(stu, stu + n, cmp);
  printf("%d\n", m);
  for(int i = 0; i < m; i++){
    printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
  }
  return 0;
}