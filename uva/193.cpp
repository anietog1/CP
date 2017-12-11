#include <iostream>
#include <vector>

using namespace std;
#define maxn 110

int tc, n, m, u, v;
vector<int> g[maxn];

int maxway[maxn];
int maxcount;

bool isblack[maxn];

void clear(){
  maxcount = 0;
  
  for(int i=1;i<=n;++i){
    g[i].clear();
    isblack[i] = false;
  }
}

void fill(int curr = 1, int blacks = 0){
  if(curr > n){
    if(blacks > maxcount){
      maxcount = blacks;
      
      for(int i=1;i<=n;++i)
	maxway[i] = isblack[i];
    }
  }else{
    bool canblack = true;
    
    for(int i=0;i<g[curr].size();++i)
      if(isblack[g[curr][i]]){
	canblack = false;
	break;
      }
  
    if(canblack){  
      isblack[curr] = true;
      fill(curr + 1, blacks + 1);
    }
    
    isblack[curr] = 0;
    fill(curr + 1, blacks);
  }
}

int main(){
  cin >> tc;

  while(tc--){
    cin >> n >> m;

    clear();
    
    while(m--){
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    
    fill();
    
    cout << maxcount << endl;
    
    for(int i=1;i<=n;++i)
      if(maxway[i]){
	cout << i;
	
	if(--maxcount)
	  cout << " ";
      }
    cout << endl;
  }
}
