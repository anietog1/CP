#include <iostream>
#include <string>

using namespace std;
#define MAXN 110
#define d(x) cout << #x << " = " << x << endl;

string dic[MAXN];
string rule;
int n, m;

void ans(int idx, string curr){
  if(idx == rule.length())
    cout << curr << endl;
  else {
    switch(rule[idx]){
    case '0':
      for(char i='0';i<='9';++i)
	ans(idx + 1, curr + i);
      break;
    case '#':
      for(int i=0;i<n;++i)
	ans(idx + 1, curr + dic[i]);
      break;
    }
  }
}

int main(){
  while(cin >> n){
    for(int i=0;i<n;++i)
      cin >> dic[i];

    cin >> m;
    while(m--){
      cin >> rule;
      cout << "--" << endl;
      ans(0, "");
    }
  }
}
