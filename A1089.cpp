const int maxn = 110;
#include <cstdio>
#include <algorithm>
using namespace std;
void Merge(int a[], int l1, int r1, int l2, int r2){
    int temp[maxn], index = 0;
    int i = l1, j = l2;
    while(i <= r1 && j <= r2){
        if(a[i] <= a[j]){
            temp[index++] = a[i++];
        }
        else temp[index++] = a[j++];
    }
    while(i <= r1) temp[index++] = a[i++];
    while(j <= r2) temp[index++] = a[j++];
    for(i = 0; i < index; i++){
        a[l1 + i] = temp[i];
    }
}
bool isSame(int a[], int b[], int n){
  for(int i = 0; i < n; i++){
    if(a[i] != b[i]) return false;
  }
  return true;
}
void OneStepOfMergeSort(int a[], int n, int step){
    if(step / 2 <= n){
        for(int i = 0; i <= n - 1; i += step){
            int mid = step / 2 + i - 1;
            if(mid + 1 <= n - 1){
                Merge(a, i, mid, mid + 1, min(i + step - 1, n - 1));
            }
        }
    }
}
void OneStepOfInsertSort(int a[], int n, int i){
    int j = i;
    while(j > 0 && a[j] < a[j-1]){
      int temp = a[j-1];
      a[j-1] = a[j];
      a[j] = temp;
      j--;
    }   
}
int main(){
  int n, a[maxn], b[maxn], c[maxn], flag = 0, mark;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    c[i] = a[i];
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &b[i]);
  }
  for(int i = 1; i < n - 1; i++){
    OneStepOfInsertSort(a, n, i);
    if(isSame(a, b, n) == true){
      printf("Insertion Sort\n");
      OneStepOfInsertSort(a, n, i + 1);
      for(int i = 0; i < n; i++){
        printf("%d", a[i]);
        if(i != n - 1) printf(" ");
      }
      return 0;
    }
  }
  printf("Merge Sort\n");
  for(int step = 2; step / 2 <= n; step *= 2){
    OneStepOfMergeSort(c, n, step);
    if(isSame(c, b, n) == true){
      OneStepOfMergeSort(c, n, step * 2);
      for(int i = 0; i < n; i++){
        printf("%d", c[i]);
        if(i != n - 1) printf(" ");
      }
      break;
    }
  }
}







