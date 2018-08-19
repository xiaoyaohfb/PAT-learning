#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[maxn];
int get_num(char name[]){
  int id = 0;
  for(int i = 0; i < 3; i++){
    id = id * 26 + name[i] - 'A';
  }
  id = id * 10 + name[3]- '0';
  return id;
}
int main(){
  int n, k;
  char name[5];
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++){
    int id, count;
    scanf("%d%d", &id, &count);
    for(int j = 0; j < count; j++){
      scanf("%s", name);
      int num = get_num(name);
      selectCourse[num].push_back(id);
    }
  }
  for(int i = 0; i < n; i++){
    scanf("%s", name);
    int num = get_num(name);
    sort(selectCourse[num].begin(), selectCourse[num].end());
    printf("%s %d", name, selectCourse[num].size());
    for(int j = 0; j < selectCourse[num].size(); j++){
      printf(" %d", selectCourse[num][j]);
    }
    printf("\n");
  }
}
