#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 50
#define D(x) cout << #x << " ) " << x << endl

vector<int> sortT;
vector<int> g[MAXN];
vector<int> rg[MAXN];
int scc[MAXN];
bool state[MAXN];

void sortT(int n){
  state[n] = true;

  for(int i=0; i<=n; ++i){
    int next = g[n][i];
    if(!state[next]) sortT(next);
  }

  sortT.push_back(n);
}

void dfs(int n, int cIdx){
  
}

int main(){
  int n, m, a, b;
  cin >> n >> m;
  
  while(m){
    cin >> a >> b;
    g[a].push_back(b);
    rg[b].push_back(a);
    --m;
  }
  
  for(int i=0; i<=n; ++i)
    scc[i] = -1;
  
  findSCC(n);
  
  for(int i=0; i<=n; ++i)
    cout << i << " = " << scc[i] << endl;
}
