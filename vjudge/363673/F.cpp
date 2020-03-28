#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)

#define MAXN 300000

map<int, vector<int>> g;

int group(int x) {
  return MAXN + x;
}

int invgroup(int x) {
  return x - MAXN;
}

map<int, bool> visited;
map<int, int> p1;
map<int, int> p2;

void dfs(int x, int pp1, int pp2) {
  visited[x] = true;
  p1[x] = pp1;
  p2[x] = pp2;

  for(int y : g[x]) {
    if(!visited[y]) {
      dfs(y, x, pp1);
    }
  }
}

int main() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) {
    int m; cin >> m;

    while(m--) {
      int d; cin >> d;
      d = group(d);
      g[i].push_back(d);
      g[d].push_back(i);
    }
  }

  dfs(1, -1, -1);

  for(int i = 1; i <= n; ++i)
    if(!visited[i]) {
      cout << "impossible" << endl;
      return 0;
    }

  for(int i = 2; i <= n; ++i) {
    cout << i << " " << p2[i] << " " << invgroup(p1[i]) << endl;
  }
}
