#include <iostream>
#include <vector>
#include <queue>
//#include <cstring>
#include <functional>

using namespace std;
#define MAXN 2001
#define pii pair<int, int>
#define INF (1 << 30)
#define d(x) cout << #x << " = " << x << endl

int main(){
  int x, n, m, k, a, b, qu;
  cin >> x;
  
  for(int cx=1;cx<=x;++cx){
    cout << "Case " << cx << ":" << endl;
    
    cin >> n >> m >> k;
    
    vector<int> g[n];
    bool airport[n] = {};
    
    while(k--){
      cin >> a;
      airport[a - 1] = true;
    }
    
    while(m--){
      cin >> a >> b;
      --a, --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    int counts[n];
    cin >> qu;
    while(qu--){
      cin >> a >> b;
      
      if(a == b){
	cout << 0 << endl;
	continue;
      }
      
      --a, --b;
      //      memset(counts, INF, n); //Useless shit :l
      for(int i=0;i<n;++i)
	counts[i] = INF;
      
      priority_queue<pii, vector<pii>, greater<pii>> q;
      
      q.push(pii(airport[a]? 0:1, a));
      
      while(!q.empty()){
	int curr = q.top().second, currcount = q.top().first;
	q.pop();
	
	// //debug
	// d(curr);
	// d(currcount);
	// for(int i=0;i<n;++i)
	//   cout << counts[i] << " ";
	// cout << endl;
	
	if(currcount < counts[curr]){
	  counts[curr] = currcount;
	  
	  for(int i=0;i<g[curr].size();++i){
	    int next = g[curr][i];
	    q.push(pii(airport[next]? currcount:currcount+1, next));
	  }
	}
      }
      
      if(counts[b] == INF)
	cout << -1 << endl;
      else
	cout << counts[b] << endl;
    }
    
    cout << endl;
  }
}
