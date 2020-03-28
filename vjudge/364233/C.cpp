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
    string str; cin >> str;
    map<pii, vector<int>> pos;

    pii curr;
    pos[curr].push_back(-1);

    for(int i = 0; i < str.size(); ++i) {
      char c = str[i];

      if(c == 'L') {
        curr.first -= 1;
      }

      if(c == 'R') {
        curr.first += 1;
      }

      if(c == 'U') {
        curr.second += 1;
      }

      if(c == 'D') {
        curr.second -= 1;
      }

      pos[curr].push_back(i);
    }

    int mind = (1 << 30);
    int mini = -(1 << 30), minj = -(1 << 30);

    for(auto it : pos) {
      vector<int> &vec = it.second;

      for(int i = 1; i < vec.size(); ++i) {
        int d = vec[i] - vec[i - 1];

        if(d < mind) {
          mind = d;
          mini = vec[i - 1];
          minj = vec[i];
        }
      }
    }

    if(mini != -(1 << 30) && minj != -(1 << 30))
      cout << mini + 2 << " " << minj + 1 << endl;
    else
      cout << -1 << endl;
  }
}
