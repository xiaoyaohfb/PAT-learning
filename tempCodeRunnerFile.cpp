const int maxn = 100;
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
void MergeSortWithFirstIndexOfZero(int a[], int n){
    for(int step = 2; step / 2 <= n; step *= 2){
        for(int i = 0; i <= n - 1; i += step){
            int mid = step / 2 + i - 1;
            if(mid + 1 <= n - 1){
                Merge(a, i, mid, mid + 1, min(i + step - 1, n - 1));
            }
        }
    }
}

int main(){
    int n, a[4];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    MergeSortWithFirstIndexOfZero(a, n);
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
}