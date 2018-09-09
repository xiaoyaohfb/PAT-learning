#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 100010;
const int maxb = 316;
int block[maxb] = {0};
int table[maxn] = {0};
stack<int> st;
int num = 0, query;
void Insert(int s1) {
  st.push(s1);
  table[s1]++;
  block[s1 / maxb]++;
}
void SelectMedian(int K) {
  int sum = 0;
  int idX = 0;
  while(sum + block[idX] < K) {
    sum += block[idX++];
  }
  int num = idX * maxb; 
  while(sum + table[num] < K) {
    sum += table[num++];
  }
  printf("%d\n", num);
}
void Pop() {
  int x = st.top();
  st.pop();
  table[x]--;
  block[x / maxb]--;
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
