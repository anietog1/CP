#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;

    int incmatrix[n][m], adjmatrix[n][n] = {};
    
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j)
	cin >> incmatrix[i][j];
    
    bool valid = true;
    for(int j=0;j<m && valid;++j){
      vector<int> incidence;
      
      for(int i=0;i<n;++i)
	if(incmatrix[i][j])
	  incidence.push_back(i);
      
      if(incidence.size() != 2)
	valid = false;
      else {
	int u = incidence[0], v = incidence[1];
	if(adjmatrix[u][v] || adjmatrix[v][u])
	  valid = false;
	else
	  adjmatrix[u][v] = adjmatrix[v][u] = true;	
      }
    }
    
    if(valid)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
