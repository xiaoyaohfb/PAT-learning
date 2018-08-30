#include <cstdio>
int a[101];
int FindFather(int x) {
    if (x == a[x]) return x;
    else {
        int F = FindFather(a[x]);
        a[x] = F;
        return F;
    }
}
int main(){
    int n, m;
    bool HashMap[101] = {false};
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        if (a[t1] == t1) a[t1] = FindFather(t2);
        else a[FindFather(t1)] = FindFather(t2);  
    }
    for (int i = 1; i <= n; i++) {
        HashMap[FindFather(i)] = true;
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (HashMap[i] == true) num++;
    }
    printf("%d", num);
}