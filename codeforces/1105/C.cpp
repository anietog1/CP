//I read some other people's code, so mine is heavily influenced :')
#include <iostream>

using namespace std;

int mod = 1e9 + 7;
int n, l, r;
long long cnts[200005][3] = {};

int main() {
  cin >> n >> l >> r;

  int c[3] = {};
  c[0] = c[1] = c[2] = (r - l) / 3;
  r -= c[0] * 3;
  for(int i = l; i <= r; ++i) ++c[i % 3];

  for(int i = 0; i < 3; ++i) cnts[0][i] = c[i];
  // cout << cnts[0][0] << " " << cnts[0][1] << " " << cnts[0][1] << endl;
  for(int i = 1; i < n; ++i) {
    cnts[i][0] = (cnts[i - 1][0] * c[0] + cnts[i - 1][1] * c[2] + cnts[i - 1][2] * c[1]) % mod;
    cnts[i][1] = (cnts[i - 1][1] * c[0] + cnts[i - 1][2] * c[2] + cnts[i - 1][0] * c[1]) % mod;
    cnts[i][2] = (cnts[i - 1][2] * c[0] + cnts[i - 1][0] * c[2] + cnts[i - 1][1] * c[1]) % mod;
    // cout << cnts[i][0] << " " << cnts[i][1] << " " << cnts[i][2] << endl;
  }

  cout << cnts[n - 1][0] << endl;
}
