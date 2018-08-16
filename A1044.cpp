#include <cstdio>
#include <cstring>
int main(){
  int n, m, sum[100010] = {0}, temp[100010][2], num = 0, flag = 0, min = 100000010;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++){
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  }
  for(int i = 1; i <= n; i++){
    int left = i - 1, right = n + 1;
    while(left < right){
      int mid = left + (right - left) / 2;
      if(sum[mid]-sum[i-1] >= m){
        right = mid;
      }
      else left = mid + 1;
    }
    if(right == n + 1) break;
    if(sum[right] - sum[i-1] == m){
      flag = 1;
      printf("%d-%d\n", i, right);
    }
    else{
      if(sum[right] - sum[i-1] < min){
        temp[0][0] = i;
        temp[0][1] = right;
        num = 1;
        min = sum[right] - sum[i-1];
      }
      else if(sum[right] - sum[i-1] == min){
        temp[num][0] = i;
        temp[num][1] = right;
        num++;
      }
    }
  }
  if(flag == 0){
    for(int i = 0; i < num; i++){
      printf("%d-%d\n", temp[i][0], temp[i][1]);
    }
  }
}