#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int maxn = 2010;
int k, numPerson = 1;
int weight[maxn] = {0};
int G[maxn][maxn];
vector<int> vec[maxn];
map<string, int> String2Num;
map<int, string> Num2String;
map<string, int> Gang;
bool vis[maxn];
void DFS(int u, int &head, int &people, int &totalWeight){
  vis[u] = true;
  people++;
  totalWeight += weight[u];
  if (weight[u] > weight[head]) head = u;
  for(int i = 0; i < vec[u].size(); i++) {
      int v = vec[u][i];
      if(!vis[v]) DFS(v, head, people, totalWeight);
  }
}

void DfsTrave(){
  for (int u = 1; u < numPerson; u++) {
    if (!vis[u]) {
      int head = u, people = 0, totalWeight = 0;
      DFS(u, head, people, totalWeight);
      if (totalWeight / 2 > k && people > 2) {
        Gang[Num2String[head]] = people;
      }
    }
  }
}

int change(string s){
  if (String2Num.find(s) != String2Num.end()) {
    return String2Num[s];
  }
  else {
    String2Num[s] = numPerson;
    Num2String[numPerson] = s;
    return numPerson++;
  }
}

int main(){
  int n, w;
  string s1, s2;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2 >> w;
    int n1 = change(s1);
    int n2 = change(s2);
    weight[n1] += w;
    weight[n2] += w;
    vec[n1].push_back(n2);
    vec[n2].push_back(n1);
  }
  DfsTrave();
  cout << Gang.size() << endl;
  for (map<string, int>::iterator it = Gang.begin(); it != Gang.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
}







