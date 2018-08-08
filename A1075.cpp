#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct Student{
  int grade[6], sum;
  int ps;
  int flag;
  int idn;
}stu[maxn];
bool cmp(Student a, Student b){
  //if(a.flag != b.flag) return a.flag > b.flag;
  if(a.sum != b.sum) return a.sum > b.sum;
  else if(a.ps != b.ps) return a.ps > b.ps;
  else return a.idn < b.idn;
}
int n, k, m;
void init(){
  for(int i = 0; i < n; i++){
    stu[i].idn = i;
    stu[i].sum = 0;
    stu[i].ps = 0;
    stu[i].flag = 0;
    memset(stu[i].grade, -1, sizeof(stu[i].grade));
  }
}
int main(){
  scanf("%d %d %d", &n, &k, &m);
  int pr[k+1];
  for(int i = 1; i <= k; i++){
    scanf("%d", &pr[i]);
  }
  init();
  for(int i = 0; i < m; i++){
    int id, p, score;
    scanf("%d%d%d", &id, &p, &score);
    if(score != -1) stu[id].flag = 1;
    if(score == -1 && stu[id].grade[p] == -1) {
      stu[id].grade[p] = 0;
      continue;
    }
    if(score > stu[id].grade[p]) {
      if(score == pr[p]) stu[id].ps++;
      /*if(stu[id].grade[p] == -1){
        stu[id].sum += score;
      }
      else stu[id].sum = stu[id].sum - stu[id].grade[p] + score;*/
      stu[id].grade[p] = score;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      if(stu[i].grade[j] != -1){
        stu[i].sum += stu[i].grade[j];
      }
    }
  }
  sort(stu+1, stu+1+n, cmp);
  int rank = 1;
  for(int i = 1; i <= n && stu[i].flag == 1; i++){
    if(stu[i].sum != stu[i-1].sum && i > 1) rank = i;
    printf("%d %05d %d", rank, stu[i].idn, stu[i].sum);
    for(int j = 1; j <= k; j++){
      if(stu[i].grade[j] != -1) printf(" %d", stu[i].grade[j]);
      else printf(" -");
    }
    printf("\n");
  }
}






