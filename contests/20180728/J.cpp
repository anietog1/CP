#include <bits/stdc++.h>

using namespace std;

int main() {
#define int unsigned long long
  int n;
  cin >> n;

  int w[n], h[n];
  for(int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  for(int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  int col[3] = {};
  for(int i = 0; i < n; ++i) {
    col[i % 3] += w[i];
  }

  int c[3] = {};

  for(int i = 0; i < n; i += 3) {
    c[0] += h[i] * col[0];
    c[1] += h[i] * col[1];
    c[2] += h[i] * col[2];
  }

  for(int i = 1; i < n; i += 3) {
    c[0] += h[i] * col[2];
    c[1] += h[i] * col[0];
    c[2] += h[i] * col[1];
  }

  for(int i = 2; i < n; i += 3) {
    c[0] += h[i] * col[1];
    c[1] += h[i] * col[2];
    c[2] += h[i] * col[0];
  }

  cout << c[1] << " " << c[2] << " " <<  c[0] << endl;
}
