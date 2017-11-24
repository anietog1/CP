//https://www.hackerrank.com/challenges/no-prefix-set/problem
#include <iostream>

using namespace std;
#define MAXN 26

struct node {
  node* children[MAXN];
  node(){
    for(int i=0;i<MAXN;++i)
      children[i] = NULL;
  }
};

node root;

bool insert(const string& s){
  node* tourist = &root;

  for(int i=0;i<s.length();++i){
    char curr = s[i] - 'a';

    if(tourist->children[curr] != NULL)
      return false;

    tourist->children[curr] = new node;
    tourist = tourist->children[curr];
  }

  return true;
}

int main(){
  int n;
  string s;
  bool isGood = true;
  
  cin >> n;
  while(n-- && isGood){
    cin >> s;
    
    if(!insert(s))
      break;
  }

  if(isGood)
    cout << "GOOD SET" << endl;
  else{
    cout << "BAD SET" << endl;
    cout << s << endl;
  }
}
