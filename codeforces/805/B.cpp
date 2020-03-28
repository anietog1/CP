#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int n; cin >> n;
  string ans = "a";

  n -= 1;
  while(n) {
    if(n >= 2) {
      if(ans[ans.size() - 1] == 'a') ans += "ab";
      else ans += "ba";
      n -= 2;
    } else {
      if(ans[ans.size() - 1] == 'a') ans += "a";
      else ans += "b";
      n -= 1;
    }
  }

  cout << ans << endl;
}
