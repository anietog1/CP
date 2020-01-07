#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int tc; cin >> tc;

  while(tc--) {
    string str; cin >> str;
    int n = str.size();

    for(int i = 1; i <= n; ++i) {
      if(n % i == 0) {
        string pat = str.substr(0, i);
        string tmp = "";

        while(tmp.size() != n) tmp += pat;
        if(tmp == str) {
          cout << pat.size() << endl;
          if(tc) cout << endl;
          break;
        }
      }
    }
  }
}
