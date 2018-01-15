#include <iostream>
#include <set>
#include <cctype>

using namespace std;
string tree;
set<string> nodes;
int nextidx;
/**
   term -> id | id '(' chil ')'
   chil -> tree reschil,
   reschil -> ',' chil | 
*/

void children();
void reschil();
void term(int);

void term(int startidx = 0){
  while(isalpha(tree[nextidx]))
    nextidx += 1;
  
  if(tree[nextidx] == '('){
    nextidx += 1;//'('
    children();
    nextidx += 1;//')'
  }
  
  nodes.insert(tree.substr(startidx, nextidx - startidx));
}

void children(){
  term(nextidx);
  reschil();
}

void reschil(){
  if(tree[nextidx] == ','){
    nextidx += 1;
    children();
  }
}

int main(){
  while(cin >> tree){
    //cleanup
    nodes.clear();
    nextidx = 0;
    //solving
    term();
    cout << nodes.size() << endl;
    //debug
    for(set<string>::iterator it=nodes.begin(); it!=nodes.end(); ++it)
      cout << *it << endl;
  }
}
