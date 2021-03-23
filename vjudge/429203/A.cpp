#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x << " = " << x << endl
#define pii pair<int, int>

int main() {
  int m, n; cin >> n >> m;
  vector<pii> g[m];
  while(n--) {
    int x, y, z; cin >> x >> y >> z;
    g[x].push_back(pii(z, y));
    g[y].push_back(pii(z, x));
  }

  bool visited[m] = {};
  priority_queue<pii, vector<pii>, greater<pii>> q;
  int sum = 0;
  q.push(pii(0, 0));
  while(!q.empty()) {
    int curr = q.top().second;
    int add = q.top().first;
    q.pop();
    if (visited[curr]) continue;
    sum += add;
    visited[curr] = true;
    
    for(int i = 0; i < g[curr].size(); i++) {
      int next = g[curr][i].second;
      int nextsum = g[curr][i].first;

      if (!visited[next]) {
        q.push(pii(nextsum, next));
      }
    }
  }

  cout << sum << endl;
}
