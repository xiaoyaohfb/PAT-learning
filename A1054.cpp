#include <map>
#include <cstdio>
using namespace std;
map<int, int> mp;
int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n * m; i++) {
    int num;
    scanf("%d", &num);
    if (mp.find(num) != mp.end()) mp[num] += 1;
    else mp[num] = 1;
  }
  int max = 0, flag;
  for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
    if(it -> second > max){
      max = it -> second;
      flag = it -> first;
    }
  }
  printf("%d", flag);
}