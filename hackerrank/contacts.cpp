//https://www.hackerrank.com/challenges/contacts/problem
#include <iostream>
#include <string>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

const int alph_size = 30;
const char base = 'a';

struct node {
  node* children[alph_size];
  int count;
  
  node(){
    for(int i=0;i<alph_size;++i)
      children[i] = NULL;
    count = 0;
  }
};

node root;

void add(const string& name){
  node* tourist = &root;
  for(int i=0;i<name.length();++i){
    char c = name[i] - base;

    if(tourist->children[c] == NULL)
      tourist->children[c] = new node;
    
    tourist = tourist->children[c];
    tourist->count += 1;
  }
}

int find(const string& partial){
  node* tourist = &root;
  
  for(int i=0;i<partial.length() && tourist!=NULL;++i){
    char c = partial[i] - base;
    tourist = tourist->children[c];
  }

  return (tourist == NULL)? 0 : tourist->count;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    string command, next;
    cin >> command >> next;
    if(command == "add")
      add(next);
    else
      cout << find(next) << endl;
  }
}
