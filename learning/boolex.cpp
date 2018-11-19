#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

string shuntingyard(string const& infix){
  stack<char> yard;
  string postfix;
  
  for(int i=0;i<infix.size();++i){
    switch(infix[i]){
    case 'T':
    case 'F':
      postfix += infix[i];
      break;
    case '(':
      yard.push('(');
      break;
    case ')':
      while(yard.top() != '('){
	postfix += yard.top();
	yard.pop();
      }
      yard.pop();
      break;
    case '|':
      while(!yard.empty() && (yard.top() != '(')){
	postfix += yard.top();
	yard.pop();
      }
      yard.push('|');
      break;
    case '&':
      while(!yard.empty() && (yard.top() != '(' && yard.top() != '|')){
	postfix += yard.top();
	yard.pop();
      }
      yard.push('&');
      break;
    case '!':
      while(!yard.empty() && (yard.top() == 'F' || yard.top() == 'T')){
	postfix += yard.top();
	yard.pop();
      }
      yard.push('!');
      break;
    }
  }
  
  while(!yard.empty())
    postfix += yard.top(), yard.pop();

#ifdef d
  d(postfix);
#endif
  
  return postfix;
}

char evaluate(string const& postfix){
  stack<char> eval;
  char a, b;
  for(int i=0;i<postfix.size();++i){
    switch(postfix[i]){
    case 'T':
    case 'F':
      eval.push(postfix[i]);
      break;
    case '|':
    case '&':
      a = eval.top(), eval.pop();
      b = eval.top(), eval.pop();
      if(postfix[i] == '|')
	eval.push((a == 'T' || b == 'T')? 'T':'F');
      else
	eval.push((a == 'T' && b == 'T')? 'T':'F');
      break;
    case '!':
      a = eval.top(), eval.pop();
      eval.push((a == 'F')? 'T':'F');
      break;
    }
  }
  
  return eval.top();
}

int main(){
  string infix;
  while(getline(cin, infix))
    cout << evaluate(shuntingyard(infix)) << endl;
}
