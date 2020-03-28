#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];

    bool cant = false;

    for(int i = 0; i < n && !cant; ++i) {
      for(int j = 0; j < n && !cant; ++j) {
        if(abs(a[i] - a[j]) % 2 == 1) {
          cant = true;
        }
      }
    }

    if(cant) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
