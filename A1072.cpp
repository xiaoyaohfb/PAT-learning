#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF= 1000000000;
const int maxn = 1000;
struct node{
    int v, dis;
    node(int _v, int _dis): v(_v), dis(_dis) {}
};
int d[maxn + 20];
bool visit[maxn + 20];
vector<node> map[maxn + 20];
int n, m, k, ds;
bool flag;
double Amin = -1;
double Asum = 0;
int String2Int(char ch[]) {
    int i = 0;
    int num = 0;
    if (ch[0] == 'G') i = 1;
    for (;i < strlen(ch); i++) {
        num *= 10;
        num += ch[i] - '0';
    }
    if (ch[0] == 'G') num += n;
    return num;
}
void Dijkstra(int s){
    fill(d, d + maxn + 20, INF);
    fill(visit, visit + maxn + 20, false);
    d[s] = 0;
    for (int i = 1; i <= n + m; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++) {
            if (!visit[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int j = 0; j < map[u].size(); j++) {
            int v = map[u][j].v;
            if (!visit[v] && d[u] + map[u][j].dis < d[v]) {
                d[v] = d[u] + map[u][j].dis;
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++) {
        char t1[5], t2[5];
        int dis;
        scanf("%s %s %d", t1, t2, &dis);
        int n1 = String2Int(t1);
        int n2 = String2Int(t2);
        map[n1].push_back(node(n2, dis));
        map[n2].push_back(node(n1, dis));
    }
    int num = 0, mark;
    for (int i = n + 1; i <= m + n; i++) {
        double minDis = INF;
        double sum = 0;
        Dijkstra(i);
        //if (i == n + 1) {
         //   for (int j = 1; j <= 7; j++) printf("%d ", d[j]);
        //}
        flag = true;
        for (int j = 1; j <= n; j++) {
            if (d[j] > ds) {
                flag = false;
                break;
            }
            if (d[j] < minDis) {
                minDis = d[j];
            }
            sum += 1.0 * d[j];
        }
        if (flag) {
            num++;
            if (minDis > Amin) {
                Amin = minDis;
                Asum = sum;
                mark = i;
            }
            else if (minDis == Amin && sum < Asum) {
                Asum = sum;
                mark = i;
            }
        }
    }
    if (num == 0) {
        printf("No Solution\n");
        return 0;
    }
    else {
        printf("G%d\n", mark - n);
        printf("%.1f %.1f", Amin, Asum / n);
    }
}
