#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
#define pii pair<int, int>
#define vii vector<pair<int,int>>

int main(){  
  int tc, n, t, e, m, a, b, w;
  
  cin >> tc;
  while(tc--){
    cin >> n >> e >> t >> m;
    vii g[n + 1];
    
    while(m--){
      cin >> a >> b >> w;
      g[a].push_back(pii(w, b));
    }

    int count = 0;
    
    for(int i=1;i<=n;++i){
      priority_queue<pii, vii, greater<pii>> q;
      int time[n + 1];

      for(int j=1;j<=n;++j)
	time[j] = 1 << 30;
      
      q.push(pii(0, i));
      time[i] = 0;
      
      while(!q.empty()){
	int cn = q.top().second, cw = q.top().first;
	q.pop();

	for(int j=0;j<g[cn].size();++j){
	  int nn = g[cn][j].second, nw = cw + g[cn][j].first;

	  if(nw < time[nn]){
	    time[nn] = nw;
	    q.push(pii(nw, nn));
	  }
	}
      }

      if(time[e] <= t)
	++count;
    }
    
    cout << count << endl;

    if(tc)
      cout << endl;
  }
}
