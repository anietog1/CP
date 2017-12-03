//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=668&problem=1246&mosmsg=Submission+received+with+ID+20435199
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 110

int n, m, u, v;
vector<int> g[MAXN];
vector<int> tsort;
bool visited[MAXN];

void dfs(int curr){
  visited[curr] = true;
  
  for(int i=0;i<g[curr].size();++i)
    if(!visited[g[curr][i]])
      dfs(g[curr][i]);
  
  tsort.push_back(curr);//This way, shortest paths are first :)
}

int main(){
  while(cin >> n >> m, (n|m)){
    for(int i=0;i<n;++i){
      g[i].clear();
      visited[i] = false;
    }

    tsort.clear();
    
    while(m--){
      cin >> u >> v;
      g[u-1].push_back(v-1);
    }

    for(int i=0;i<n;++i)
      if(!visited[i])
	dfs(i);

    reverse(tsort.begin(), tsort.end());
    
    for(int i=0;i<n;++i)
      cout << tsort[i] + 1 << " ";
    cout << endl;
  }
}
