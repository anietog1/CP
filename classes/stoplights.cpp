#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int matrix[n+1][n+1] = {};//gonna work 1 index
  while(m--){//build matrix
    int u, v;
    cin >> u >> v;
    matrix[u][v] = matrix[v][u] = true;
  }
  bool colored[n+1] = {};//init colored
  vector<vector<int>> groups;//init groups
  for(int i=1;i<=n;++i){
    if(!colored[i]){
      bool forbidden[n+1] = {};//init forbidden
      for(int j=1;j<=n;++j){
	if(matrix[i][j]){//forbid connected ones
	  forbidden[j] = true;
	}
      }
      for(int j=1;j<=n;++j){
	if(!colored[j]/*added this param, for making less groups (avoiding take always smaller nums)*/ && !forbidden[j]){//if it will contain j, then forbid forbidden ones for j
	  for(int k=1;k<=n;++k){
	    if(matrix[j][k]){//forbid forbidden ones for j
	      forbidden[k] = true;
	    }
	  }
	}
      }
      
      vector<int> currgroup;//make group
      for(int j=1;j<=n;++j){
	if(!forbidden[j]){//if can ally with j, then do it
	  colored[j] = true;
	  currgroup.push_back(j);
	}
      }
      groups.push_back(currgroup);//add the new group
    }
  }
  
  for(int i=0;i<groups.size();++i){//print groups
    cout << "Group #" << i << ":" << endl;
    for(int j=0;j<groups[i].size();++j){
      if(j){
	cout << " ";
      }
      cout << groups[i][j];
    }
    cout << endl;
  }
}

//Notes:
//First solution did always choose smaller numbers, then leaving a lot of groups
//Second solution (current one) is, without I even noticed, the same as the one in the book...
