#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1010];
bool sprout = true;

int dfs(int curr = 1){
  if(!sprout)
    return 0;
  
  if(g[curr].size() == 0)
    return 1;
  else {
    int count = 0;
    
    for(int i=0;i<g[curr].size();++i)
      count += dfs(g[curr][i]);
    
    if(count < 3)
      sprout = false;
    
    return 0;
  }
}

int main(){
  int n;
  cin >> n;
  
  for(int i=1;i<n;++i){
    int p;
    cin >> p;
    g[p].push_back(i+1);
  }
  
  dfs();
  
  if(sprout)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
