#include <cstdio>

using namespace std;

#define read(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

struct node{
  int val;
  node *left, *right;

  node(int val)
    : val(val), left(NULL), right(NULL){}
};

node* root = NULL;

//Tomado del Laboratorio 5. El metodo es perfecto para esta situación
node* insert(node *curr, int x){
  if(curr == NULL)
    return new node(x);

  if(x < curr->val)
    curr->left = insert(curr->left, x);
  
  else if(x > curr->val)
    curr->right = insert(curr->right, x);

  return curr;
}

void insert(int x){
  root = insert(root, x);
}

void printPost(node *curr){
  if(curr == NULL)
    return;
  
  printPost(curr->left);
  printPost(curr->right);
  print(curr->val);
}

void printPost(){
  printPost(root);
}

int main(){
  int x;
  
  while(read(x) == 1){
    insert(x);
  }
  
  printPost();
  
  return 0;
}
