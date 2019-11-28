#include <bits/stdc++.h>

using namespace std;

int sqrt(int x) {
  return x / 2;
}

int main(int argc, char** argv, char** env) {
  int n;
  cin >> n;

  int ans = 1000000000;

  for(int a = 1; a * a <= n; ++a) {
    int b = n / a;

    if(a * b == n) {
      int curr = 2 * a + 2 * b;
      ans = min(ans, curr);
    }
  }

  cout << ans << endl;
}
