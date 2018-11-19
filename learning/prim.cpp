#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
//Better dense
using namespace std;
#define MAXN 100
#define pii pair<int,int>

vector<pii> g[MAXN] = {};
bool visited[MAXN] = {};

int prim(int n){
  for(int i=0; i < n; ++i)
    visited[i] = false;
  
  priority_queue<pii,vector<pii>,greater<pii> > q;
  int total = 0;
  
  q.push(pii(0,0));
  while(!q.empty()){
    int curr = q.top().second;
    int w = q.top().first;
    q.pop();

    if(visited[curr])
      continue;

    visited[curr] = true;
    total += w;
    for(int i=0; i< g[curr].size(); ++i)
      if(!visited[ g[curr][i].second ])
	q.push( g[curr][i] );
  }

  return total;
}

int main(){
  int n, m, i, j, w;
  scanf("%d %d", &n, &m);
  while(m){
    scanf("%d %d %d", &i, &j, &w);
    g[i].push_back(pii(w,j));
    g[j].push_back(pii(w,i));
    --m;
  }

  printf("%d",prim(n));
}
