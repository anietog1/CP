#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
#define MAXN 100005

int tc, n, m, x, y;
vector<int> g[MAXN];
vector<int> invg[MAXN];
bool visited[MAXN];
vector<int> topo;

void dfs1(int i) {
  visited[i] = true;
  for(int j : g[i]) {
    if(!visited[j]) {
      dfs1(j);
    }
  }
  topo.push_back(i);
}

void dfs2(int i) {
  visited[i] = true;
  for(int j : invg[i]) {
    if(!visited[j]) {
      dfs2(j);
    }
  }
}

int main() {
  cin >> tc;
  while(tc--) {
    cin >> n >> m;

    topo.clear();
    for(int i = 0; i < n; ++i) {
      g[i].clear();
      invg[i].clear();
    }
    memset(visited, false, sizeof(bool) * n);

    while(m--) {
      cin >> x >> y;
      g[x-1].push_back(y-1);
      invg[y-1].push_back(x-1);
    }

    for(int i = 0; i < n; ++i) {
      if(!visited[i]) dfs1(i);
    }

    reverse(topo.begin(), topo.end());

    int count = 0;
    memset(visited, false, n * sizeof(bool));
    for(int i = 0; i < n; ++i) {
      if(!visited[topo[i]]) dfs1(topo[i]), count+=1;
    }

    cout << count << endl;
  }
}
