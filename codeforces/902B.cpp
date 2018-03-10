#include <bits/stdc++.h>

using namespace std;
#define maxn 10010

int n, goal[maxn];
vector<int> g[maxn];
bool visited[maxn] = {};
int steps = 0;

void dfs(int u = 1, int prev = 0){
  visited[u] = true;
  if(prev != goal[u])
    ++steps;
  for(int i=0;i<g[u].size();++i)
    if(!visited[g[u][i]])
      dfs(g[u][i], goal[u]);
}

int main(){
  cin >> n;
  for(int i=2;i<=n;++i){
    int pi;
    cin >> pi;
    g[pi].push_back(i);
    g[i].push_back(pi);
  }
  
  for(int i=1;i<=n;++i)
    cin >> goal[i];
  
  dfs();
  cout << steps << endl;
}
