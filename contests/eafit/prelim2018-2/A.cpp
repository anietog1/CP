#include <bits/stdc++.h>

using namespace std;
//#define debug
#ifdef debug
 #define d(x) cout << #x << " = " << x << endl
#else
 #define d(x) 0
#endif

int const maxn = 3 * 10000 + 10;

vector<int> g[maxn];
bool visited[maxn] = {};

vector<int> order;

void dfs(int c) {
  visited[c] = true;

  for(int i = 0; i < g[c].size(); ++i) {
    if(!visited[g[c][i]]) {
      dfs(g[c][i]);
    }
  }

  d(c);
  order.push_back(c);
}

int main() {
  int n, m;
  cin >> n >> m;

  while(m--) {
    int a, b;
    cin >> a >> b;
    d(a), d(b);
    g[b].push_back(a);
  }

  for(int i = 1; i <= n; ++i) {
    if(!visited[i]) {
      dfs(i);
    }
  }

  reverse(order.begin(), order.end());

  cout << order[0];
  for(int i = 1; i < n; ++i) {
    cout << " " << order[i];
  }
  cout << endl;
}
