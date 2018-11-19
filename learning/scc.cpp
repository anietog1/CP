#include <iostream>
#include <vector>
#include <algorithm>
//Kusaraju's algorithm with 1-index
using namespace std;

#define MAXN 100
#define D(x) cout << #x << " =  " << x << endl

vector<int> sortT;
vector<int> g[MAXN];
vector<int> rg[MAXN];
int scc[MAXN];
bool state[MAXN];

int n;

void sortTop(int s){
  state[s] = true;

  for(int i=0; i<g[s].size(); ++i){
    int next = g[s][i];
    if(!state[next]) sortTop(next);
  }

  sortT.push_back(s);
}

void dfs(int s, int cIdx){//Armando las scc
  scc[s] = cIdx;
  
  for(int i=0; i < rg[s].size(); ++i){
    int next = rg[s][i];
    if(scc[next] == -1) dfs(next, cIdx);
  }
}

void findSCC(){
  for(int i=1; i<=n; ++i)
    if(!state[i]) sortTop(i);
  reverse(sortT.begin(), sortT.end());

  int cIdx = 1;
  for(int i=0; i<sortT.size(); ++i){
    int next = sortT[i];
    if(scc[next] == -1){
      dfs(next, cIdx);
      ++cIdx;
    }
  }
}

void reset(){
  sortT.clear();

  for(int i=1; i<=n; ++i){
    state[i] = false;
    g[i].clear();
    rg[i].clear();
    scc[i] = -1;
  }
}

int main(){
  int m, a, b;
  cin >> n >> m;
  reset();
  
  while(m){
    cin >> a >> b;
    g[a].push_back(b);
    rg[b].push_back(a);
    --m;
  }

  findSCC();
  
  for(int i=1; i<=n; ++i)
    cout << i << " = " << scc[i] << endl;
}
