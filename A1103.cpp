#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int maxSum = -1;
int n, k, p;
vector<int> temp, ans;
void DFS(int num, int sum, int nowK, int factorSum) {
  if (nowK == k && sum == n) {
    if (factorSum > maxSum) {
      maxSum = factorSum;
      ans = temp;
    }
    else if (factorSum == maxSum) {
      vector<int>::iterator it1 = ans.begin();
      vector<int>::iterator it2 = temp.begin();
      for (int i = 0; i < k; i++) {
        if (*it1 == *it2) {
          it1++;
          it2++;
          continue;
        }
        else if (*it1 < *it2) {
          ans = temp;
        }
        return;
      } 
    }
  }
  if (num == 0 || nowK == k || sum > n) return;
  temp.push_back(num);
  DFS(num, sum + pow(num, p), nowK + 1, factorSum + num);
  temp.pop_back();
  DFS(num - 1, sum, nowK, factorSum);
}
int main(){
  scanf("%d%d%d", &n, &k, &p);
  DFS(21, 0, 0, 0);
  if (ans.size() == 0) printf("Impossible\n");
  else {
    printf("%d = ", n);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
      if (it + 1 != ans.end()) printf("%d^%d + ", *it, p);
      else printf("%d^%d", *it, p);
    }
  }
}
