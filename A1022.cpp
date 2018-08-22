#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
map<string, set<int>> title, auth, key, publish, year;
void query(map<string, set<int>>& mp, string& str){
  if (mp.find(str) == mp.end()) printf("Not Found\n");
  else {
    for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
      printf("%07d\n", *it);
    }
  }
}
int main(){
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) { 
    int num;
    string title1, auth1, key1, publish1, year1;
    scanf("%d", &num);
    char c = getchar();
    getline(cin, title1);
    title[title1].insert(num);
    getline(cin, auth1);
    auth[auth1].insert(num);
    while (cin >> key1) {
      key[key1].insert(num);
      c = getchar();
      if (c == '\n') break;
    }
    getline(cin, publish1);
    publish[publish1].insert(num);
    getline(cin, year1);
    year[year1].insert(num);
  }
  int query1, type;
  scanf("%d", &query1);
  string rec;
  for (int i = 0; i < query1; i++) {
    scanf("%d: ", &type);
    getline(cin, rec);
    cout << type << ": " << rec << endl;
    if(type == 1) query(title, rec);
    else if(type == 2) query(auth, rec);
    else if(type == 3) query(key, rec);
    else if(type == 4) query(publish, rec);
    else query(year, rec);
  }
  return 0;
}