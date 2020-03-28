#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)

int main() {
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    int n = s.size();
    int d = 1;
    int lastr = n;
    for(int i = n - 1; i >= 0; --i) {
      if(s[i] == 'R') {
        d = max(d, (lastr - i));
        //        D(lastr);
        //D(i);
        lastr = i;
        //D(d);
      }
    }

    d = max(d, lastr + 1);
    
    cout << d << endl;
  }
}
