#include <cstdio>
#include <queue>
using namespace std;
int a[1001], n, num = 0, temp = 0;
bool flag = true;
struct Node{
  Node* left;
  Node* right;
  int data;
};
Node* NewNode(int data){
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
void insert(Node* &root, int x){
  if (root == NULL) {
    root = NewNode(x);
    return;
  }
  if (x < root->data) insert(root->left, x);
  else insert(root->right, x);
}
Node* Create(int a[], int n){
  Node* root = NULL;
  for (int i = 0; i < n; i++) {
    insert(root, a[i]);
  }
  return root;
}
void PreTravese(Node* root) {
  if (root == NULL) return;
  else {
    if (root->data != a[temp]) flag = false;
    temp++;
  }
  PreTravese(root->left);
  PreTravese(root->right);
}
void PostTraverse(Node* root) {
  if (root == NULL) return;
  PostTraverse(root->left);
  PostTraverse(root->right);
  printf("%d", root->data);
  num++;
  if (num != n) printf(" ");
}
void Swap(Node* root) {
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    Node* front = q.front();
    q.pop();
    Node* temp = front->left;
    front->left = front->right;
    front->right = temp;
    if (front->left != NULL)q.push(front->left);
    if (front->right != NULL)q.push(front->right);
  }
}
int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  Node* root = Create(a, n);
  PreTravese(root);
  if (flag) {
    printf("YES\n");
    PostTraverse(root);
  }
  else {
    temp = 0;
    flag = true;
    Swap(root);
    PreTravese(root);
    if (flag) {
      printf("YES\n");
      PostTraverse(root);
    }
    else printf("NO");
  }
}













