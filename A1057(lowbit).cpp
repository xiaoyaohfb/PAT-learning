#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i)&(-i))
int c[maxn] = {0}, query;
stack<int> st;
void update(int x, int v){
  for (int i = x; i < maxn; i += lowbit(i)) {
    c[i] += v; 
  } 
}
int getnumber(int x){
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    sum += c[i];
  }
  return sum;
}
void Insert(int s1) {
  st.push(s1);
  update(s1, 1);
}
void SelectMedian(int K) {
  int sum = 0;
  int l = 1, r = maxn - 1;
  while(l < r) {
    int mid = (l + r) / 2;
    if (getnumber(mid) >= K) r = mid;
    else l = mid + 1;
  }
  printf("%d\n", l);
}
void Pop() {
  int x = st.top();
  st.pop();
  update(x, -1);
  printf("%d\n", x);
}
int main(){
  scanf("%d", &query);
  char ch[12];
  for (int i = 0; i < query; i++) {
    scanf("%s", ch);
    if (!strcmp(ch, "Pop")) {
      if (st.size() == 0) {
        printf("Invalid\n");
      }
      else {
        Pop();
      }
    }
    else if (!strcmp(ch, "Push")) {
      int num1;
      scanf("%d", &num1);
      Insert(num1);
    }
    else {
      if (st.size() == 0) printf("Invalid\n");
      else {
        int K = st.size();
        if (K % 2 == 1) K = (K + 1) / 2;
        else K = K / 2;
        SelectMedian(K);
      }
    }
  }
  return 0;
}