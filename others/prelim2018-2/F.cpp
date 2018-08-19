#include <bits/stdc++.h>

using namespace std;
#define maxn 10010

vector<int> g[maxn];
bool visited[maxn];
int sum;

void dfs(int x) {
  if(visited[x]) {
    return;
  }

  visited[x] = true;
  ++sum;
  for(int i = 0; i < g[x].size(); ++i) {
    dfs(g[x][i]);
  }
}

int main() {
  int tc;
  cin >> tc;

  while(tc--) {
    int n, m, l;
    cin >> n >> m >> l;

    sum = 0;
    for(int i = 0; i <= n; ++i) {
      visited[i] = false;
      g[i].clear();
    }

    while(m--) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
    }

    while(l--) {
      int z;
      cin >> z;
      dfs(z);
    }

    cout << sum << endl;
  }
}
