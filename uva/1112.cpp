#include <bits/stdc++.h>

using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int n, e, t, m;
    cin >> n >> e >> t >> m;
    
    int g[n+1][n+1];
    
    for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
	g[i][j] = 1 << 20;
    
    for(int i=1;i<=n;++i)
      g[i][i] = 0;
    
    while(m--){
      int a, b, time;
      cin >> a >> b >> time;
      g[a][b] = time;
    }
    
    for(int u=1;u<=n;++u)
      for(int v=1;v<=n;++v)
	for(int w=1;w<=n;++w)
	  g[v][w] = min(g[v][w], g[v][u] + g[u][w]);
    
    int count = 0;
    for(int i=1;i<=n;++i)
      if(g[i][e] <= t)
	++count;
    
    cout << count << endl;
    if(tc)
      cout << endl;
  }
}
