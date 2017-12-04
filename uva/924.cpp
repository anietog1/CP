#include <iostream>
#include <queue>
#include <functional>

using namespace std;
#define pii pair<int, int>
#define vi vector<int>

int e, n, t;
vi g[2510];

int main(){
  cin >> e;
  for(int i=0;i<e;++i){
    cin >> n;
    
    while(n--){
      int j;
      cin >> j;
      g[i].push_back(j);
    }
  }

  cin >> t;
  while(t--){
    bool visited[e] = {};
    int day[e] = {};
    
    int fmaxday = 0;
    int max = 0;
    
    int source;
    cin >> source;
    
    queue<pii> q;
    q.push(pii(source, 0));
    
    while(!q.empty()){
      int ce = q.front().first;	
      int cday = q.front().second;
      q.pop();

      if(visited[ce])
	continue;
      
      visited[ce] = true;
      
      if(++day[cday] > max && cday){
	max = day[cday];
	fmaxday = cday;
      }
      
      //      cout << "day " << cday << ", e " << ce << endl;
            
      for(int i=0;i<g[ce].size();++i){
	int ne = g[ce][i];
	
	if(!visited[ne])
	  q.push(pii(ne, cday + 1));
      }
    }
    
    if(day[1])
      cout << max << " " << fmaxday << endl;
    else
      cout << 0 << endl;
  }
}
