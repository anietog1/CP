#include <bits/stdc++.h>
//#define D(x) cout << #x << " = " << x << endl
#define D(x) 0

using namespace std;

int count0(string s) {
  int cnt = 0;
  for(char c : s) {
    cnt += c == '0';
  }
  return cnt;
}

int main() {
  int tc; cin >> tc;
  while(tc--) {
    int n; cin >> n;
    string s; cin >> s;
    bool no = count0(s) % 2 != 0 || s[0] == '0' || s[n - 1] == '0';

    if(no) {
      cout << "NO" << endl;
    } else {
      string as, bs;

      int height = 0;
      bool switcher = true;
      for(int i = 1; i < s.size() - 1; i++) {
        char c = s[i];

        if(c == '1') {
          if(height > 0) {
            as += ')';
            bs += ')';
            height--;
          } else {
            as += '(';
            bs += '(';
            height++;
          }
        } else {
          if(switcher) {
            as += '(';
            bs += ')';
          } else {
            as += ')';
            bs += '(';
          }

          switcher = !switcher;
        }
      }

      cout << "YES" << endl;
      cout << '(' << as << ')' << endl;
      cout << '(' << bs << ')' << endl;
    }
  }
}
