#include <bits/stdc++.h>

#define pii pair<int,int>
#define vii vector<pii>
#define MAXN 100
#define INF 1 << 30
#define D(x) cout << #x << " = " << x << endl;

using namespace std;

vii g[MAXN];
int w[MAXN];
int maxd;

void dijkstra(int n){
  priority_queue< pii, vii, greater<pii> > q;
  w[n] = 0;
  q.push(pii(0,n));//pair <w,s>
  while(!q.empty()){
    int curr = q.top().second;
    int lastW = q.top().first;
    q.pop();

    for(int i=0; i < g[curr].size(); ++i){
      int next = g[curr][i].second;
      int currW = lastW + g[curr][i].first;

      if(currW < w[next]){
	w[next] = currW;
	if(currW > maxd) maxd = currW;
	q.push(pii(currW, next));
      }
    }
  }
}

void reset(){
  maxd = 0;
  for(int i=0; i<MAXN; ++i){
    g[i].clear();
    w[i] = INF;
  }
}

int min(int a, int b, int c){
  if(b < a) a = b;
  if(c < a) a = c;
  return a;
}

int main(){
  int N,S;
  int sA,sB,sC;
  int i, j, w;

  while(cin >> N && cin >> S){
    reset();
    while(S){
      cin >> i >> j >> w;
      g[i].push_back(pii(w,j));
      g[j].push_back(pii(w,i));
      --S;
    }

    for(int i=0; i<N; ++i)
      dijkstra(i);
    
    cin >> sA >> sB >> sC;
    cout << ceil((double)maxd / min(sA,sB,sC));
  }
  
  return 0;
}
