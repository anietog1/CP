#include <bits/stdc++.h>
//#define D(x) cout << #x << " = " << x << endl
#define D(x) 0

using namespace std;

string inverse(string s) {
  string inv;
  for(char c : s) {
    inv += (c == '0')? '1' : '0';
  }
  return inv;
}

bool validslice(string s) {
  int cnt0 = 0, cnt1 = 0;
  for(char c : s) {
    cnt0 += (c == '0');
    cnt1 += (c == '1');
  }
  return cnt0 == cnt1;
}

int main() {
  int tc; cin >> tc;
  while(tc--) {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    D(a), D(b);

    vector<string> aslices, bslices;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; ++i) {
      cnt0 += a[i] == '0';
      cnt1 += a[i] == '1';

      if((cnt0 == cnt1) || (i == n - 1)) {
        int sum = (cnt0 + cnt1);

        string aslice = a.substr(i + 1 - sum, sum);
        string bslice = b.substr(i + 1 - sum, sum);
        D(aslice), D(bslice);

        aslices.push_back(aslice);
        bslices.push_back(bslice);
        cnt0 = cnt1 = 0;
      }
    }

    bool yes = true;
    for(int i = 0; i < aslices.size(); ++i) {
      bool eqslices = aslices[i] == bslices[i];
      bool invslices = inverse(aslices[i]) == bslices[i];
      bool validaslice = validslice(aslices[i]);

      if(!(eqslices || (invslices && validaslice))) {
        yes = false;
      }
    }

    if(yes) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
