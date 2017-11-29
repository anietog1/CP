#include <iostream>
#include <vector>

using namespace std;
#define MAXN 2005

vector<int> g[MAXN];
bool visited[MAXN];
int n, m, u, v, p;

void dfs(int curr){
  visited[curr] = true;

  for(int i=0;i<g[curr].size();++i){
    int next = g[curr][i];
    
    if(!visited[next])
      dfs(next);
  }
}

bool good(int curr){
  for(int i=1;i<=n;++i)
    visited[i] = false;
  
  dfs(curr);

  for(int i=1;i<=n;++i)
    if(!visited[i])
      return false;

  return true;
}

int main(){
  cin >> n >> m;
  while(n | m){
    for(int i=1;i<=n;++i)
      g[i].clear();
    
    while(m--){
      cin >> u >> v >> p;

      g[u].push_back(v);
      
      if(p == 2)
	g[v].push_back(u);
    }
    
    bool nice = true;

    for(int i=1;i<=n;++i)
      if(!good(i)){
	nice = false;
	break;
      }
    
    cout << nice << endl;
    cin >> n >> m;
  }
}
