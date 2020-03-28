#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
#define MAXN 1000000

int p[MAXN];
int cnt = MAXN;

int find(int x) {
  return p[x] == x? x : p[x] = find(p[x]);
}

void join(int x, int y) {
  int px = find(x), py = find(y);
  if(px != py) {
    p[py] = px;
    cnt--;
  }
}

int main() {
  int n, m, _tc = 0;
  while(cin >> n >> m, n | m) {
    _tc++;
    cout << "Case " << _tc << ": ";
    for(int i = 0; i < n; ++i) p[i] = i;
    cnt = n;

    while(m--) {
      int i, j; cin >> i >> j;
      i--, j--;
      join(i, j);
    }

    cout << cnt << endl;
  }
}
