#include <cstdio>
const int maxn = 100;
int round = 1;
int a[100], b[100];
int c[100] = {-1};
struct node{
    int data;
    node* left;
    node* right;
};
void reconstruct(int on, int off, int round, int on1, int off1){
    if (on > off) {
        return;
    }
    int data = a[on];
    c[round] = data;
    int k;
    for (int i = on1; i <= off1; i++) {
        if (b[i] == data) {
            k = i;
            break;
        }
    }
    int numLeft = k - on1;
    reconstruct(on + 1, on + numLeft, 2 * round, on1, k - 1);
    reconstruct(on + numLeft + 1, off, 2 * round + 1, k + 1, off1);
}
node* reconstructByPointer(int on, int off, int on1, int off1){
    if (on > off) {
        return NULL;
    }
    node* root = new node;
    root->data = a[on];
    int k;
    for (int i = on1; i <= off1; i++) {
        if (b[i] == root->data) {
            k = i;
            break;
        }
    }
    int numLeft = k - on1;
    root->left = reconstructByPointer(on + 1, on + numLeft, on1, k - 1);
    root->right = reconstructByPointer(on + numLeft + 1, off, k + 1, off1);
    return root;
}

int main(){
    for (int i = 1; i <= 8; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 8; i++) {
      scanf("%d", &b[i]);
    }
    reconstruct(1, 8, 1, 1, 8);
    for(int i = 1; i < 15; i++) {
        printf("%d", c[i]);
    }
}