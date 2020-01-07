#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  string str; cin >> str;

  int n = str.size();
  int Z[n] = {};
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

  vector<int> oks;
  int counts[n] = {};

  for(int i = 0; i < n; ++i) {
    if(i + Z[i] == n)
      oks.push_back(Z[i]);
    ++counts[Z[i]];
  }

  for(int i = n - 2; i >= 0; --i)
    counts[i] += counts[i + 1];

  cout << oks.size() + 1 << endl;

  for(int i = oks.size() - 1; i >= 0; --i)
    cout << oks[i] << " " << counts[oks[i]] + 1 << endl;

  cout << n << " " << 1 << endl;
}
