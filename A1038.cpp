#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
bool cmp(string s1, string s2){
  return s1 + s2 < s2 + s1;
}
int main(){
  string s[10010];
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  sort(s, s + n, cmp);
  string ans;
  for(int i = 0; i < n; i++){
    ans += s[i];
  }
  while(ans.size() != 0 && ans[0] == '0'){
    ans.erase(ans.begin());
  }
  if(ans.size() == 0) cout << 0;
  else cout << ans;
}