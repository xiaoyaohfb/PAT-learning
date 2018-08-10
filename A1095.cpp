#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct Car {
    char id[8];    // 车牌号
    int time;    // 记录的时刻，以秒为单位
    char status[4];    // in或者out
}all[maxn], valid[maxn];    // all记录所有记录，valid为有效记录
int num = 0;    // 有效记录的条数
map<string, int> parkTime;    // 车牌号->总停留时间
// timeToInt将时间转换为以秒为单位
int timeToInt(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}
// 先按车牌号字典序从小到大排序，相同的按时间从小到大排序
bool cmpByIdAndTime(Car a, Car b) {
    if(strcmp(a.id, b.id)) return strcmp(a.id, b.id) < 0;
    else return a.time < b.time;
}
// 按时间从小到大排序
bool cmpByTime(Car a, Car b) {
    return a.time < b.time;
}
int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  int hh, mm, ss;
  for(int i = 0; i < n; i++){
    scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
    all[i].time = timeToInt(hh, mm, ss);
  }
  sort(all, all + n, cmpByIdAndTime);
  int maxTime = -1;
  for(int i = 0; i < n - 1; i++){
    if(!strcmp(all[i].id, all[i + 1].id) && !strcmp(all[i].status, "in") && !strcmp(all[i+1].status, "out")){
      valid[num++] = all[i];
      valid[num++] = all[i+1];
      if(parkTime.count(all[i].id) == 0){
        parkTime[all[i].id] = 0;
      }
      int intime = all[i + 1].time - all[i].time;
      parkTime[all[i].id] += intime;
      maxTime = max(maxTime, parkTime[all[i].id]);
    }
  }
  
  sort(valid, valid + num, cmpByTime);
  int now = 0, numCar = 0;
  for(int i = 0; i < k; i++){
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int time = timeToInt(hh, mm ,ss);
    while(now < num && valid[now].time <= time){
      if(!strcmp(valid[now].status, "in")) numCar++;
      else numCar--;
      now++;
    }
    printf("%d\n", numCar);
  }
  map<string, int>::iterator it;
  for(it = parkTime.begin(); it != parkTime.end(); it++){
    if(it->second == maxTime){
      printf("%s ", it->first.c_str());
    }
  }
  printf("%02d:%02d:%02d\n", maxTime/3600, maxTime%3600/60, maxTime%60);
}


















