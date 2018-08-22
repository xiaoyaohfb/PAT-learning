#include <queue>
#include <cstdio>
using namespace std;
struct node{
  int weight;
  int rank;
}mice[1010];
queue<int> q;
int main(){
  int rank[1010], n, m, order;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &mice[i].weight);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &order);
    q.push(order);
  }
  int temp = n, group;
  while(q.size() != 1) {
    if(temp % m == 0) group = temp / m;
    else group =  temp / m + 1;
    for(int i = 0; i < group; i++) {
      int k = q.front();
      for(int j = 0; j < m; j++) {
        if(i * m + j >= temp) break;
        int front = q.front();
        if(mice[front].weight > mice[k].weight) {
          k = front;
        }
        mice[front].rank = group + 1;
        q.pop();
      }
      q.push(k);
    }
    temp = group;
  }
  mice[q.front()].rank = 1;
  for(int i = 0; i < n; i++) {
    printf("%d", mice[i].rank);
    if(i != n - 1) printf(" ");
  }
}