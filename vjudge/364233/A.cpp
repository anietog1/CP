#include <bits/stdc++.h>

using namespace std;

#define D(x)  cout << #x << " = " << x << endl
#define pii   pair<int, int>
#define pll   pair<long, long>
#define ll    long long
#define float double

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      sum += a[i];
    }

    if(sum & 1) {
      cout << "YES" << endl;
    } else {
      if(n == 1) {
        cout << "NO" << endl;
      } else {
        bool hasodd = false;
        bool haseven = false;
        for(int i = 0; i < n; ++i) {
          if(a[i] & 1) hasodd = true;
          else haseven = true;
        }

        if(hasodd && haseven) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
  }
}
