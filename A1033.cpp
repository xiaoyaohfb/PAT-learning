#include <cstdio>
#include <algorithm>
using namespace std;
struct Station {
  double price, dis;
}sta[510];
bool cmp(Station a, Station b){
  return a.dis < b.dis;
}
int main(){
  int N;
  double C, D, Davg; 
  scanf("%lf%lf%lf%d", &C, &D, &Davg, &N);
  for(int i = 0; i < N; i++){
    scanf("%lf%lf", &sta[i].price, &sta[i].dis);
  }
  sta[N].price = 0;
  sta[N].dis = D;
  sort(sta, sta + N, cmp);
  if(sta[0].dis != 0) {
    printf("The maximum travel distance = 0.00");
    return 0;
  }
  int curS = 0;
  double sum = 0, nowTank = 0, MXADIS = Davg * C;
  while(curS < N){
    double min = 100000000;
    int flag = -1;
    for(int i = curS + 1; i <= N && sta[i].dis - sta[curS].dis <= MXADIS; i++){
      if(sta[i].price < min){
        min = sta[i].price;
        flag = i;
      }
      if(min < sta[curS].price) break;
    }
    if(flag == -1) break;
    double need = (sta[flag].dis - sta[curS].dis) / Davg;
    if(min > sta[curS].price){
      sum += (C - nowTank) * sta[curS].price;
      nowTank = C - need;
    }
    else{
      if(nowTank < need){
        sum += (need - nowTank) * sta[curS].price;
        nowTank = 0;
      }
      else nowTank = nowTank - need;
    }
    curS = flag;
  }
  if(curS == N) printf("%.2f", sum);
  else printf("The maximum travel distance = %.2f", sta[curS].dis + MXADIS);
}