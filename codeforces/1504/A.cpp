#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc; cin >> tc;
  while(tc--) {
    string s; cin >> s;
    int cnta = 0;
    for(char c: s) {
      if(c == 'a') {
        cnta++;
      }
    }

    if(cnta == s.size()) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      int sa = 0, fa = 0;
      for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'a') sa++;
        else break;
      }

      for(int i = s.size() - 1; i >= 0; --i) {
        if(s[i] == 'a') fa++;
        else break;
      }

      if(sa >= fa) cout << 'a' << s << endl;
      else cout << s << 'a' << endl;
    }
  }
}
