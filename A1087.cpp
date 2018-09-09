#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 201;
const int INF = 1000000000;
map<string, int> String2Int;
map<int, string> Int2String;
struct node{
  int v, dis;
  node(int _v, int _dis): v(_v), dis(_dis) {}
};
vector<node> vec[maxn];
vector<int> tempPath, path;
vector<int> pre[maxn];
int d[maxn];
int count1 = 1, n;
int weight[maxn];
int OptValue = -1, ansAver;
bool visit[maxn] = {false};
int NumOfRoute = 0;
int change(string s){
  if (String2Int.find(s) != String2Int.end()){
    return String2Int[s];
  }
  else {
    String2Int[s] = count1;
    Int2String[count1] = s;
    return count1++;
  }
}
void Dijkstra(int s){
  fill(d, d + maxn, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, MIN = INF;
    for (int j = 0; j < n; j++) {
      if (visit[j] == false && d[j] < MIN) {
        MIN = d[j];
        u = j;
      }
    }
    if (u == -1) return;
    visit[u] = true;
    for (int j = 0; j < vec[u].size(); j++) {
      int v = vec[u][j].v;
      if (!visit[v]) {
        if (d[u] + vec[u][j].dis < d[v]) {
          d[v] = d[u] + vec[u][j].dis;
          pre[v].clear();
          pre[v].push_back(u);
        }
        else if (d[u] + vec[u][j].dis == d[v]) 
          pre[v].push_back(u);
      }
    }
  }
}
int CalValue(){
  int value = 0;
  for (int i = tempPath.size() - 1; i >= 0; i--) {
    value += weight[tempPath[i]];
  }
  return value;
}
void DFS(int v){
  if (v == 0) {
    int value = CalValue();
    NumOfRoute++;
    if (value > OptValue) {
      OptValue = value;
      path = tempPath;
      int num = tempPath.size();
      ansAver = value / num;
    }
    else if (value == OptValue) {
      int num = tempPath.size();
      int ave = value / num;
      if (ave > ansAver) {
        path = tempPath;
        ansAver = ave;
      }
    }
    return;
  }
  tempPath.push_back(v);
  for (int i = 0; i < pre[v].size(); i++) {
    DFS(pre[v][i]);
  }
  tempPath.pop_back();
}
int main(){
  int k, happy;
  string s;
  cin >> n >> k >> s;
  String2Int[s] = 0;
  Int2String[0] = s;
  for (int i = 0; i < n - 1; i++) {
    cin >> s >> happy;
    int id = change(s);
    weight[id] = happy;
  }
  for (int i = 0; i < k; i++) {
    string s1, s2;
    int dis;
    cin >> s1 >> s2 >> dis;
    int n1, n2;
    n1 = String2Int[s1];
    n2 = String2Int[s2];
    vec[n1].push_back(node(n2, dis));
    vec[n2].push_back(node(n1, dis));
  }
  Dijkstra(0);
  int end = String2Int["ROM"];
  DFS(end);
  printf("%d %d %d %d\n", NumOfRoute, d[end], OptValue, ansAver);
  cout << Int2String[0];
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << "->" << Int2String[path[i]];
  }
}










