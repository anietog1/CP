#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;
#define pcs pair<char, string>
#define MAXN 30

int n, cnt;
pcs codes[MAXN];
string encripted;

void solve(int idx = 0, string curr = ""){
  if(cnt >= 100);
  else if(idx == encripted.length()){
    ++cnt;
    cout << curr << endl;
  } else {
    for(int i=0;i<n;++i){
      string& code = codes[i].second;
      
      if(code == encripted.substr(idx, code.length()))
	solve(idx + code.length(), curr + codes[i].first);
      else if('0' + code == encripted.substr(idx, code.length() + 1))
	solve(idx + code.length() + 1, curr + codes[i].first);
    }
  }
}

int main(){
  int tc = 1;
  while(cin >> n, n){
    for(int i=0;i<n;++i)
      cin >> codes[i].first >> codes[i].second;
    
    sort(codes, codes + n);

    cnt = 0;
    cin >> encripted;
    cout << "Case #" << tc++ << endl;
    solve();
    cout << endl;
  }
}
