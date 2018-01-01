#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int const c = 5, r = 6, n = 100;

int t, k;
bool first[c][n], second[c][n];
vector<string> passwords;
char curr[c];

void solve(int col = 0){
  if(col == c)
    passwords.push_back(curr);
  else if(passwords.size() < k)
    for(char i='A';i<='Z';++i)
      if(first[col][i] && second[col][i]){
	curr[col] = i;
	solve(col + 1);
      }
}

int main(){
  cin >> t;
  while(t--){
    cin >> k;
    
    passwords.clear();
    for(int i=0;i<c;++i)
      for(int j='A';j<='Z';++j)
	first[i][j] = second[i][j] = false;
    
    string tempr[r];
    
    for(int i=0;i<r;++i){
      cin >> tempr[i];
      for(int j=0;j<c;++j)
	first[j][tempr[i][j]] = true;
    }
    
    for(int i=0;i<r;++i){
      cin >> tempr[i];
      for(int j=0;j<c;++j)
	second[j][tempr[i][j]] = true;
    }
    
    solve();
    
    if(passwords.size() < k)
      cout << "NO" << endl;
    else
      cout << passwords[k - 1] << endl;
  }
}
