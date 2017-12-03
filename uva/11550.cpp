#include <iostream>

//just stupid mistakes...

using namespace std;
bool g[10][100];
int t, n, m;

bool good(){
  bool con[10][10] = {};
  
  for(int j=0;j<m;++j){
    int u, v, count = 0;
    
    for(int i=0;i<n;++i){
      if(g[i][j]){
	if(!count)
	  u = i;
	else
	  v = i;
	
	++count;
      }
    }

    if(count != 2)
      return false;

    if(con[u][v])
      return false;
    
    con[u][v] = con[v][u] = true;
  }

  return true;
}

int main(){
  cin >> t;
  while(cin >> n >> m){
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j)
	cin >> g[i][j];
    
    if(good())
      cout << "Yes" << endl;
    else
      cout << "No"<< endl;
  }
}
