#include <iostream>
#include <vector>
#include <algorithm>

//Better sparse
using namespace std;
#define MAXN 100

struct edge{
  int u,v,w;
  edge(int u, int v, int w):u(u),v(v),w(w){}
  bool operator<(edge &other){
      return w < other.w;
  }
};

vector<edge> g;
int p[MAXN];
int n;

void init(){
  for(int i=0; i < n; ++i)
    p[i] = i;
  g.clear();
}

int find(int i){
  return (p[i] == i)? i: p[i] = find(p[i]);
}

void merge(int i, int j){
  p[i] = j;
}

int kruskal(){
  sort(g.begin(), g.end());
  int count = 0;
  int total = 0;

  for(int i=0; i < g.size() && count < n; ++i){
    int x = find(g[i].u);
    int y = find(g[i].v);
    
    if(x != y){
      merge(x, y);
      total += g[i].w;
      ++count;
    }
  }
  
  return total;
}

int main(){
  cin >> n;
  int m;
  cin >> m;
  
  init();
  while(m){
    int i,j,w;
    cin >> i >> j >> w;
    g.push_back(edge(i, j, w));
    g.push_back(edge(j, i, w));
    --m;
  }
  
  cout << kruskal() << endl;
  
  return 0;
}
