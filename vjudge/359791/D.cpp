#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  string s;
  while(cin >> s) {
    int n = s.size();

    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
      while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
      }
      d1[i] = k--;
      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }

    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
      while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
      }
      d2[i] = k--;
      if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
      }
    }

    int idx = -1;
    for(int i = 0; i < n; ++i) {
      if(i + d2[i] == n) {
        idx = i - d2[i];
        break;
      }

      if(i + d1[i] == n) {
        idx = i - (d1[i] - 1);
        break;
      }
    }

    string toAppend = s.substr(0, idx);
    cout << s << string(toAppend.rbegin(), toAppend.rend()) << endl;
  }
}
