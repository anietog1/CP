#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 100010

int t, n, m, u, v;
vector<int> g[MAXN];
bool visited[MAXN];
vector<int> tsort;

void dfs(int curr, bool sorttop = false){
  visited[curr] = true;
  
  for(int i=0;i<g[curr].size();++i){
    int next = g[curr][i];
    
    if(!visited[next]){
      dfs(next);
    }
  }
  
  if(sorttop)
    tsort.push_back(curr);
}

int main(){
  cin >> t;

  while(cin >> n >> m, t--){
    tsort.clear();
    tsort.reserve(2*n);
    
    for(int i=1;i<=n;++i){
      g[i].clear();
      visited[i] = false;
    }
    
    while(m--){
      cin >> u >> v;
      g[u].push_back(v);
    }

    for(int i=1;i<=n;++i)
      if(!visited[i])
	dfs(i, true);

    reverse(tsort.begin(), tsort.end());

    int count = 0;

    for(int i=1;i<=n;++i)
      visited[i] = false;
    
    for(int i=0;i<tsort.size();++i)
      if(!visited[tsort[i]]){
	++count;
	dfs(tsort[i]);
      }
    
    cout << count << endl;
  }
}
