#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(int argc, char** argv, char** env) {
  int t; cin >> t;
  while(t--) {
    int cnt[10];
    for(int i = 0; i < 10; ++i) cin >> cnt[i];

    int min_with_cnt = -1;
    for(int i = 1; i < 10; ++i) {
      if(cnt[i] != 0) {
        min_with_cnt = i;
        break;
      }
    }

    int min_cnt = cnt[1], min_idx = 1;
    for(int i = 2; i < 10; ++i) {
      if(cnt[i] < min_cnt) {
        min_cnt = cnt[i];
        min_idx = i;
      }
    }

    if(cnt[0] < min_cnt) {
      cout << min_with_cnt;
      for(int i = 0; i <= cnt[0]; ++i) cout << 0;
    } else {
      for(int i = 0; i <= min_cnt; ++i) cout << min_idx;
    }

    cout << endl;
  }
}
