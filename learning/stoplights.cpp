#include <iostream>
#include <vector>

using namespace std;
//Complexity: O(n**3)
//Without noticing, the solution is the same presented in the book
/*
 * The other solution was:
 * for each node in g
 * |for each color in g
 * |||color node with color
 * |||if adjacent to a node with same color
 * |||color with next color
 * ||repeat
 * 
 * The complexity of this one was O(n**3) too, but is way more
 * difficult to implement.
 */
int main(){
  int n, m;
  cin >> n >> m;
  int matrix[n+1][n+1] = {};
  while(m--){
    int u, v;
    cin >> u >> v;
    matrix[u][v] = matrix[v][u] = true;
  }
  bool colored[n+1] = {};
  vector<vector<int>> groups;
  for(int i=1;i<=n;++i)
    if(!colored[i]){
      bool forbidden[n+1] = {};
      
      for(int j=i;j<=n;++j)
	if(!colored[j] && !forbidden[j])
	  for(int k=1;k<=n;++k)
	    if(matrix[j][k])
	      forbidden[k] = true;
      
      vector<int> currgroup;
      for(int j=1;j<=n;++j)
	if(!forbidden[j]){
	  colored[j] = true;
	  currgroup.push_back(j);
	}
      groups.push_back(currgroup);
    }
  
  for(int i=0;i<groups.size();++i){
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
