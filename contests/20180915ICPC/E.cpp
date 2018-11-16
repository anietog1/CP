#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int const maxn = 100000 + 5;
int ft[maxn];

int LSOne(int i) {
  return i & (-i);
}

int rsq(int b) {
  int sum = 0;
  for(; b; b -= LSOne(b)) sum += ft[b];
  return sum;
}

void adjust(int k, int v) {
  for(; k < maxn; k += LSOne(k)) ft[k] += v;
}

int main() {
  int m, n;
  while(cin >> m >> n) {
    fill(ft, ft + m * n + 5, 0);

    int board[m][n];
    int dist;

    int invs = 0, idx = 0;
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        int val;
        cin >> val;

        invs += (idx++) - rsq(val);
        adjust(val, 1);

        if(val == m * n)
          dist = (m - i - 1) + (n - j - 1);
      }
    }

    if((invs + dist) & 1)
      cout << "N" << endl;
    else
      cout << "Y" << endl;
  }
}
