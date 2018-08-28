#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 10;
int fol[26][maxn];

int main() {
  int n;
  cin >> n;

  while(n--) {
    string str;
    cin >> str;

    for(int i = 0; i < 26; ++i) {
      fol[i][str.size()] = -1;
    }

    for(int i = str.size() - 1; i >= 0; --i) {
      for(int j = 0; j < 26; ++j) {
        fol[j][i] = fol[j][i + 1];
      }

      fol[str[i] - 'A'][i] = i;
    }

    int cnt = 0;

    for(int i = 0; i < 26; ++i) {
      int a = fol[i][0];

      if(a != -1) {
        for(int j = 0; j < 26; ++j) {
          int b = fol[j][a + 1];

          if(b != -1) {
            for(int k = 0; k < 26; ++k) {
              int c = fol[k][b + 1];

              if(c != -1) {
                ++cnt;
              }
            }
          }
        }
      }
    }

    cout << cnt << endl;
  }
}
