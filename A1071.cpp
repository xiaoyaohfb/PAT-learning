#include <map>
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
map<string, int> mp;
bool check(char c){
  if (c >= 'A' && c <='Z') return true;
  if (c >= 'a' && c <='z') return true;
  if (c >= '0' && c <='9') return true;
  return false;
}
bool cmp(string a, string b){
  int len1 = a.length();
  int len2 = b.length();
  for (int i = 0; i <= len1 && i <= len2; i++){
    if(a[i] != b[i]) return a[i] < b[i];
  }
  return len1 < len2;
}
int main(){
    string str;
    getline(cin, str);
    int on = -1, off = -1;
    int num = str.length();
    for (int i = 0; i < num; i++) {
        if (check(str[i]) == true) {
          if (str[i] >= 'A' && str[i] <='Z') {
                str[i] = str[i] + 32; //to_lower
          }
          if (on == -1) on = i;
        }
        else if (on != -1){
            off = i - 1;
        }
        if (off != -1) {
            string temp = str.substr(on, off - on + 1);
            if (mp.find(temp) != mp.end()) {
                mp[temp] += 1;
            }
            else mp[temp] = 1;
            on = -1, off = -1;
        }
    }
    int max = -1;
    string flag;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it -> second > max) {
          max = it -> second;
          flag = it -> first;
        }
    }
    printf("%s %d", flag.c_str(), max);
}