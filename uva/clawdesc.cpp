//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=669&page=show_problem&problem=2391
#include <iostream>
#include <vector>
#include <queue>

//Condition: every vertex's grade = 3.
//A claw is K1,3

using namespace std;
#define MAXN 305

int n, u, v;
vector<int> g[MAXN];

bool check(){//bipartite check
  int vals[n + 1] = {};
  queue<int> q;

  q.push(1);
  vals[1] = 1;

  while(!q.empty()){
    int curr = q.front();
    q.pop();

    for(int i=0;i<g[curr].size();++i){
      int next = g[curr][i];
      if(! vals[next]){
	vals[next] = vals[curr] == 1? 2 : 1;
	q.push(next);
      }else if(vals[next] == vals[curr])
	return false;
    }
  }

  return true;
}

int main(){
  while(cin >> n, n){
    for(int i=1;i<=n;++i) //cleanup
      g[i].clear();
    
    while(cin >> u >> v, (u | v)){
      g[u].push_back(v);
      g[v].push_back(u);
    }

    if(check())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
