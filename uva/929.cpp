#include <iostream>
#include <queue>
#include <functional>

using namespace std;
#define MAXN 1000
#define pii pair<int, int>
#define piii pair<int, pii>

int const INF = 1 << 30;

int tc, n, m;
int g[MAXN][MAXN];
int w[MAXN][MAXN];

int main(){
  cin >> tc;
  while(tc--){
    cin >> n >> m;
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j){
	cin >> g[i][j];
	w[i][j] = INF;
      }

    priority_queue<piii, vector<piii>, greater<piii>> q;
    q.push(piii(g[0][0], pii(0, 0)));
    w[0][0] = g[0][0];
    
    while(!q.empty()){
      int cr = q.top().second.first, cc = q.top().second.second, cw = q.top().first;
      q.pop();
      
      if(cr < n - 1){
	int nr = cr + 1;
	int nw = cw + g[nr][cc];
	
	if(nw < w[nr][cc]){
	  w[nr][cc] = nw;
	  q.push(piii(nw, pii(nr, cc)));
	}
      }

      if(cr > 0){
	int nr = cr - 1;
	int nw = cw + g[nr][cc];
	
	if(nw < w[nr][cc]){
	  w[nr][cc] = nw;
	  q.push(piii(nw, pii(nr, cc)));
	}
      }

      if(cc < m - 1){
	int nc = cc + 1;
	int nw = cw + g[cr][nc];
	
	if(nw < w[cr][nc]){
	  w[cr][nc] = nw;
	  q.push(piii(nw, pii(cr, nc)));
	}
      }

      if(cc > 0){
	int nc = cc - 1;
	int nw = cw + g[cr][nc];
	
	if(nw < w[cr][nc]){
	  w[cr][nc] = nw;
	  q.push(piii(nw, pii(cr, nc)));
	}
      }
    }

    // for(int i=0;i<n;++i){
    //   for(int j=0;j<m;++j)
    //     cerr << w[i][j] << " ";
    //   cerr << endl;
    // }
    
    cout << w[n-1][m-1] << endl;
  }
}
