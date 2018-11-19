#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
#define MAXN 500
#define D(x) cout << #x << "= " << x << endl
 
vector<int> g[MAXN];
int d[MAXN], p[MAXN];
bool state[MAXN];
 
void bfs(int s, int n) {
  for(int i = 0; i <= n; ++i) d[i] = p[i] = -1;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(int i = 0; i < g[curr].size(); ++i) {
      int next = g[curr][i];
      if(d[next] == -1) {
        d[next] = d[curr] + 1;
        p[next] = curr;
        q.push(next);
        //D(next); D(d[next]); D(curr); D(d[curr]);
      }
    }
  }
}
 
void dfs(int u) {
  state[u] = true;
  for(int i = 0; i < g[u].size(); ++i) {
    int next = g[u][i];
    if(!state[next]) dfs(next);
  }
}
 
int main() {
  int n, m, q;
  cin >> n >> m;
  while(m--) {
    int x, y;
    cin >> x >> y;
    //D(x); D(y);
    g[x].push_back(y);
  }
  cin >> q;
  while(q--) {
    int curr;
    cin >> curr;
    bfs(curr, n);
    for(int i = 0; i <= n; ++i) state[i] = false;
    dfs(curr);
    for(int i = 1; i <= n; ++i) {
      //cout << "to : " << i << " with : " << d[i] << endl;
    }
    for(int i = 1; i <= n; ++i) {
      cout << "Dfs to: " << i << "with: " << state[i] << endl;
    }
  }
}
