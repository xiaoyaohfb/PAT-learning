#include <cstdio>
const int maxn = 100;
int round = 1;
int a[200], b[200];
int c[10000] = {0};

void reconstruct(int on, int off, int round, int on1, int off1){
    if (on > off) {
        return;
    }
    int data = a[off];
    c[round] = data;
    int k;
    for (int i = off1; i >= on1; i--) {
        if (b[i] == data) {
            k = i;
            break;
        }
    }
    int numLeft = k - on1;
    reconstruct(on, on + numLeft - 1, 2 * round, on1, k - 1);
    reconstruct(on + numLeft, off - 1, 2 * round + 1, k + 1, off1);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
    }
    reconstruct(1, n, 1, 1, n);
    int num = 0;
    for (int i = 1; i < 20000; i++) {
      if (c[i] != 0) {
        printf("%d", c[i]);
        num++;
        if (num != n) printf(" ");
        else break;
      }
    }
}