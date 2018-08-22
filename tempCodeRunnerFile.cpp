#include <cstdio>
int main(){
    int a[4];
    for(int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("%d", a[i]);
    }
    for(int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("%d", a[i]);
    }
}