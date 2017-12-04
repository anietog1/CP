#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
#define pii pair<int, int>
#define vii vector<pii>

int const INF = (1 << 30);

int dijkstra(vii g[], int n, int s, int t){
  int time[n];

  for(int i=0;i<n;++i)
    time[i] = INF;
  
  priority_queue<pii, vii, greater<pii>> q;
  q.push(pii(0,s));
  time[s] = 0;

  while(!q.empty()){
    int cn = q.top().second, cw = q.top().first;
    q.pop();
    
    for(int i=0;i<g[cn].size();++i){
      int nn = g[cn][i].second, nw = cw + g[cn][i].first;
      
      if(nw < time[nn]){
	time[nn] = nw;
	q.push(pii(nw, nn));
      }
    }
  }
  
  return time[t];
}

int main(){
  int N;
  cin >> N;
  for(int x=1;x<=N;++x){
    int n, m, S, T;
    cin >> n >> m >> S >> T;
    vii g[n];
    
    while(m--){
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back(pii(w,v));
      g[v].push_back(pii(w,u));
    }
    
    int time = dijkstra(g, n, S, T);
    
    cout << "Case #" << x << ": ";
    if(time < INF)
      cout << time << endl;
    else
      cout << "unreachable" << endl;
  }
}
