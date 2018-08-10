#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
  char name[11];
  char id[11];
  int grade;
  int flag;
}stu[100010];
bool cmp(Student a, Student b){
  if(a.flag != b.flag) return a.flag > b.flag;
  else return a.grade > b.grade;
}
int main(){
  int n, g1, g2;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
    stu[i].flag = 0;
  }
  scanf("%d %d", &g1, &g2);
  int num = 0;
  for(int i = 0; i < n; i++){
    if(stu[i].grade >= g1 && stu[i].grade <= g2){
      stu[i].flag = 1;
      num++;
    }
  }
  if(num == 0){
    printf("NONE");
  }
  else{
    sort(stu, stu + n, cmp);
    for(int i = 0 ;i < num; i++){
      printf("%s %s\n", stu[i].name, stu[i].id);
    }
  }
}











