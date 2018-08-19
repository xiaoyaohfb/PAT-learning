#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2510;
vector<int> course[maxn];
int get_num(char name[]){
  int id = 0;
  for(int i = 0; i < 3; i++){
    id = id * 26 + name[i] - 'A';
  }
  id = id * 10 + name[3]- '0';
  return id;
}
void get_name(char name[], int num){
  name[3] = num % 10 + '0';
  num /= 10;
  for(int i = 2; i >= 0; i--){
    name[i] = num % 26 + 'A';
    num /= 26;
  }
}
int main(){
  int n, k, count, num, j, id;
  char name[5];
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%s", name);
    num = get_num(name);
    scanf("%d", &j);
    while(j--){
      scanf("%d", &id);
      course[id].push_back(num);
    }
  }
  for(int i = 1; i <= k; i++){
    printf("%d %d\n", i, course[i].size());
    sort(course[i].begin(), course[i].end());
    for(int j = 0; j < course[i].size(); j++){
      get_name(name, course[i][j]);
      printf("%s\n", name);
    }
  }
}