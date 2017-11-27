//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=669&page=show_problem&problem=945
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAXN 210

vector<int> g[MAXN];
int n, l, u, v;

bool isB(){
  int vals[n] = {};//there was the mistake hahahaha
  queue<int> q;
  
  q.push(0);
  vals[0] = 1;
  
  while(!q.empty()){
    int curr = q.front();
    q.pop();

    for(int i=0; i<g[curr].size(); ++i){
      int next = g[curr][i];

      if(vals[next] == 0){
	if(vals[curr] == 1)
	  vals[next] = 2;
	else
	  vals[next] = 1;
	
        q.push(next);
      }else if(vals[next] == vals[curr])
        return false;
    }
  }

  // for(int i=0;i<n;++i)
  //   cout << vals[i] << " ";

  // cout << endl;
  
  return true;
}

int clear(){
  for(int i=0;i<n;++i)
    g[i].clear();
}

int main(){
  cin >> n;
  while(n){
    clear();
    cin >> l;

    for(int i=0;i<l;++i){
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    if(isB())
      cout << "BICOLORABLE." << endl;
    else
      cout << "NOT BICOLORABLE." << endl;
    
    cin >> n;
  }
};
