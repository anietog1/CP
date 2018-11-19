#include <vector>
#include <utility>
#include <queue>
#include <iostream>

#define pii pair<int, int>
#define vii vector<pii>
#define MAXN 100
#define INF 1<<30

using namespace std;
//data is saved as pair [weight, node]
vector<pii> g[MAXN];
//w-> distances from source to the other nodes
int w[MAXN];

void dijkstra(int s){
  priority_queue< pii, vector<pii>, greater<pii> > q;//This is how u reverse the ordering using the first
  w[s] = 0;
  q.push( pii(0,s) );// pair [w,s]
  
  while(!q.empty()){
    int curr = q.top().second;
    int lastW = q.top().first;
    q.pop();
    
    for(int i=0; i < g[curr].size(); ++i){
      int next = g[curr][i].second;
      int currW = lastW + g[curr][i].first;

      if(currW < w[next]){
	w[next] = currW;
	q.push( pii(currW, next) );//Esto era lo que fallaba :)
      }
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  ++n;
  for(int i=0; i < n; ++i)
    *(w + i) = INF;

  while(m > 0){
    int i, j, w;
    cin >> i >> j >> w;
    //CORREJIR
    g[i].push_back(pii(w,j));
    --m;
  }
  
  int s;
  cin >> s;
  dijkstra(s);
  for(int i=0; i<n; ++i)
    cout << "W from " << s << " to " << i << " with " << w[i] << endl;
}
