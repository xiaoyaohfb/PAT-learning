#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
using namespace std;
int main(){
  string str;
  getline(cin, str);
  while(str.length() > 0 && str[0] != '"'){
    str.erase(str.begin());
  }
  str.erase(str.begin());
  printf("%s", str.c_str());
}