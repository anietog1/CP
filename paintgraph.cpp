#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAXN 1000
vector<int> g[MAXN];

bool canPaint(int n){
  int vals[n];
  queue<int> q;
  
  q.push(0);
  vals[0] = 1;
  
  while(!q.empty()){
    int curr = q.front();
    q.pop();

    for(int i=0; i<g[curr].size(); i++){
      int next = g[curr][i];

      if(vals[next] == 0){
	if(vals[curr] == 1){
	  vals[next] = 2;
	}else{
	  vals[next] = 1;
	}
      }else if(vals[next] == vals[curr]){
        return false;
      }
      
      q.push(next);
    }
  }
  
  return true;
}
//USING 0 INDEX
//1 -> rojo 2 -> verde 0-> nada
int main(){
  //n -> n nodos, q -> union de vertices
  int n, q;
  cin >> n >> q;
  
  while(q>0){
    int i, j;
    cin>>i>>j;
    g[i].push_back(j);
  }
  
  cout << canPaint(n);
  return 0;
}
