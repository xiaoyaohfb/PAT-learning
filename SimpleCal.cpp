#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
struct node{
    double num;
    char op;
    bool flag;
};
map<char, int> mp;
queue<node> q;
stack<node> s;
string str;

void Create(){
    node temp;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + str[i] - '0';
            }
            q.push(temp);
        }
        else {
            temp.flag = false;
            temp.op = str[i];
            if (!s.empty() && mp[s.top().op] >= mp[str[i]]) {
                q.push(s.top());
                s.pop();
            }
            s.push(temp);
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
double cal(){
    node cur, temp;
    double temp1, temp2;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.flag == true) {
            s.push(cur);
        }
        else {
            temp1 = s.top().num;
            s.pop();
            temp2 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op == '+') temp.num = temp1 + temp2;
            else if (cur.op == '-') temp.num = temp1 - temp2;
            else if (cur.op == '*') temp.num = temp1 * temp2;
            else temp.num = temp1 / temp2;
            s.push(temp);
        }
        return s.top().num;
    }
}
int main(){
    getline(cin, str);
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ' ') str.erase(it);
    }
    while (!s.empty()) s.pop();
    Create();
    printf("%.2f", cal());
}