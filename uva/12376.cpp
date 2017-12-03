#include <iostream>
#include <vector>

using namespace std;
#define MAXN 110

int T, n, m, u, v, point[MAXN];
vector<int> g[MAXN];
int endNode = 0;

int max(int curr){
  if(g[curr].size() == 0){
    endNode = curr;
    return 0;
  }
  
  int maxPoints = 0;
  int maxNode;
  
  for(int i=0;i<g[curr].size();++i){
    int next = g[curr][i];

    if(point[next] > maxPoints){
      maxPoints = point[next];
      maxNode = next;
    }
  }

  return maxPoints + max(maxNode);
}

int main(){
  cin >> T;
  for(int i=1;i<=T; ++i){
    cin >> n >> m;
    
    for(int i=0;i<n;++i){
      cin >> point[i];
      g[i].clear();
    }
    
    while(m--){
      cin >> u >> v;
      g[u].push_back(v);
    }

    int ans = max(0);
    cout << "Case " << i << ": " << ans << " " << endNode << endl;
  }
}
