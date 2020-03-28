#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  string A; getline(cin, A);
  string B; getline(cin, B);
  int cnt; cin >> cnt;

  string str = B + "$" + A;

  int n = str.size();
  int Z[n] = {(int) B.size()};
  int L, R;

  L = R = 0;
  for(int i = 1; i < n; ++i) {
    if(i > R) {
      L = R = i;
      while(str[R] == str[R - L] && R < n)
        ++R;
      Z[i] = R - L;
      --R;
    } else {
      int k = i - L;

      if(Z[k] < R - i + 1) {
        Z[i] = Z[k];
      } else {
        L = i;
        while(str[R] == str[R - L] && R < n)
          ++R;
        Z[i] = R - L;
        --R;
      }
    }
  }

  int counts[n] = {};
  for(int i = B.size(); i < n; ++i) {
    counts[Z[i]] += 1;
  }

  for(int i = n - 2; i >= 0; --i) {
    counts[i] += counts[i + 1];

    if(counts[i] >= cnt && i != 0) {
      cout << B.substr(0, i) << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;
}
