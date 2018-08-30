#include <cstdio>
#include <algorithm>
using namespace std;
bool Compare(int a[], int b[], int n){
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
bool Compare1(int a[], int b[], int n){
  for (int i = 0; i < n; i++) {
    if (a[i+1] != b[i]) return false;
  }
  return true;
}
void Insertion(int a[], int i){
  int j = i - 1;
  int temp = a[i];
  while (j >=0 && a[j] > temp) {
    a[j+1] = a[j];
    j--;
  }
  if (j != i - 1) {
    a[j + 1] = temp;
  }
}
void DownAdjust(int a[], int low, int high){
  int i = low, j = i * 2;
  while (j <= high) {
    if (j + 1 <= high && a[j + 1] > a[j]) j = j + 1;
    if (a[j] > a[i]) {
      swap(a[i], a[j]);
      i = j;
      j = 2 * i;
    } else {
        break;
    }
  }
}
void CreateHeap(int a[], int n){
  for (int i = n / 2; i >= 1; i--){
    DownAdjust(a, i, n);
  }
}
void HeapSort(int a[], int i){
  swap(a[i], a[1]);
  DownAdjust(a, 1, i - 1);
}
int main(){
  int a[101], b[101], c[102];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    c[i+1] = a[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i < n; i++) {
    Insertion(a, i);
    if (Compare(a, b, n)) {
      Insertion(a, i + 1);
      printf("Insertion Sort\n");
      for (int j = 0; j < n; j++) {
        printf("%d", a[j]);
        if (j != n - 1) printf(" ");
      }
      return 0;
    }
  }
  CreateHeap(c, n);
  printf("Heap Sort\n");
  for (int i = n; i > 1; i--) {
    HeapSort(c, i);
    if (Compare1(c, b, n)) {
      HeapSort(c, i - 1);
      for (int j = 1; j <= n; j++) {
        printf("%d", c[j]);
        if (j != n) printf(" ");
      }
      return 0;
    }
  }
}














