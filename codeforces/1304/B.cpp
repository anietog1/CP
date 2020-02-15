#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  int n, m; cin >> n >> m;
  string str[n];
  for(int i = 0; i < n; ++i) cin >> str[i];

  bool ispal[n][n] = {};
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      ispal[i][j] = true;
      for(int k = 0; k < m; ++k) {
        if(str[i][k] != str[j][m - k - 1]) {
          ispal[i][j] = false;
          break;
        }
      }
    }
  }

  string ans;
  bool used[n] = {};

  for(int i = 0; i < n; ++i) {
    bool isalone = true;

    for(int j = 0; j < n; ++j) {
      if(i != j && ispal[i][j]) {
        isalone = false;
        break;
      }
    }

    if(isalone && ispal[i][i]) {
      used[i] = true;
      ans = str[i];
      break;
    }
  }
  
  for(int i = 0; i < n; ++i) {
    if(!used[i]) {
      int p = -1;

      for(int j = 0; j < n; ++j) {
        if(!used[j] && i != j && ispal[i][j]) {
          p = j;
          break;
        }
      }

      if(p != -1) {
        ans = str[i] + ans + str[p];
        used[i] = used[p] = true;
      }
    }
  }

  cout << ans.size() << endl;
  cout << ans << endl;
}
