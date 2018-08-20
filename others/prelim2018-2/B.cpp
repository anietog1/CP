#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int const maxn = 2 * 100000 + 10;

int n, m, q;

vector<int> g[maxn];
vector<int> inv_g[maxn];

vector<int> order;
bool visited[maxn];

void dfs1(int x) {
  visited[x] = true;

  for(int i = 0; i < g[x].size(); ++i) {
    if(!visited[g[x][i]]) {
      dfs1(g[x][i]);
    }
  }

  order.push_back(x);
}

int p[maxn];

int parent(int i) {
  return p[i] == i? i : p[i] = parent(p[i]);
}

void join(int x, int y) {
  p[x] = parent(y);
}

void dfs2(int x, int g) {
  visited[x] = true;
  join(x, g);

  for(int i = 0; i < inv_g[x].size(); ++i) {
    if(!visited[inv_g[x][i]]) {
      dfs2(inv_g[x][i], g);
    }
  }
}

void scc() {
  order.reserve(n);
  for(int i = 1; i <= n; ++i) {
    if(!visited[i]) {
      dfs1(i);
    }
  }

  reverse(order.begin(), order.end());

  fill(visited, visited + n, false);
  for(int i = 1; i <= n; ++i) {
    p[i] = i;
  }

  for(int i = 1; i <= n; ++i) {
    if(!visited[i]) {
      dfs2(i, i);
    }
  }
}

int main() {
  cin >> n >> m >> q;

  map<pii, int> r_cnt;

  while(m--) {
    int u, v;
    cin >> u >> v;

    if(u < v) {
      swap(u, v);
    }

    g[u].push_back(v);

    if(r_cnt[pii(u, v)]++) {
      g[v].push_back(u);
    }
  }

  scc();

  bool wrong = false;

  while(q--) {
    int s, d;
    cin >> s >> d;

    if(s < d) {
      swap(s, d);
    }

    if(parent(s) != parent(d)) {
      wrong = true;
      break;
    }
  }

  cout << (wrong? "No" : "Yes") << endl;
}
