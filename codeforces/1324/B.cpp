#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    map<int, vector<int>> pos;

    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < n; ++i) {
      pos[a[i]].push_back(i);
    }

    bool exists = false;
    for(auto vec : pos) {
      if(vec.second.size() > 2) exists = true;
      if(vec.second.size() == 2) {
        if(abs(vec.second[0] - vec.second[1]) > 1) {
          exists = true;
        }
      }
    }

    if(exists) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
