#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
  int data;
  int height;
  node* left;
  node* right;
}*root;
int getHeight(node* root){
  if (root == NULL) return 0;
  else return root->height;
}
void updateHeight(node* root){
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(node *root) {
  return getHeight(root->left) - getHeight(root->right);
}
node* newNode(int x){
  node* n = new node;
  n->height = 1;
  n->data = x;
  n->left = NULL;
  n->right = NULL;
  return n;
}
void L(node* &root) {
  node* temp = root->right;
  root->right = temp->left;
  temp->left = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void R(node* &root) {
  node* temp = root->left;
  root->left = temp->right;
  temp->right = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void insert(node* &root, int data){
  if (root == NULL) {
    root = newNode(data);
  }
  else if (data < root->data) {
    insert(root->left, data);
    updateHeight(root);
    if (getBalanceFactor(root) == 2) {
      if (getBalanceFactor(root->left) == 1) {
          R(root);
      }
      else {
          L(root->left);
          R(root);
      }
    }
  }
  else {
    insert(root->right, data);
    updateHeight(root);
    if (getBalanceFactor(root) == -2) {
      if (getBalanceFactor(root->right) == -1) {
          L(root);
      } else {
          R(root->right);
          L(root);
      }
    }
  }
}
int main(){
  int n, v;
  scanf("%d", &n);
  root =NULL;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    insert(root, v);
  }
  printf("%d\n", root->data);
}














