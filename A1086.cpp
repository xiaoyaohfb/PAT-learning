#include <cstdio>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
  bool flag;
};
int count = 0;
int n;
stack<Node*> s;
Node* newNode(int data){
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->flag = false;
  return node;
}
void PostOrder(Node* root){
  if (root == NULL) 
    return;
  PostOrder(root->left);
  PostOrder(root->right);
  printf("%d", root->data);
  count++;
  if (count != n) printf(" ");
}
int main(){
  int d;
  char temp[6];
  Node* root;
  Node* pre;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%s", temp);
    if (!strcmp(temp, "Push")) {
      scanf("%d", &d);
      Node* node = newNode(d);
      if (i == 0) {
        root = node;
      }
      else {
        if (pre->flag == false) pre->left = node;
        else pre->right = node;
      }
      pre = node;
      s.push(node);
    }
    else {
      if (!s.empty()) {
        pre = s.top();
        s.pop();
        pre->flag = true;
      }
    }
  }
  PostOrder(root);
}