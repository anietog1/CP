#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
int n, m, u, v;
vector<vector<int>> g;
vector<int> colours;

void paint(int curr){
  vector<bool> forbiddens(g.size());
  
  for(int i=0;i<g[curr].size();++i){//forbidding neighbouring colours
    int neighbourscolour = colours[g[curr][i]];
    
    if(neighbourscolour != - 1)
      forbiddens[neighbourscolour] = true;
  }
  
  for(int i=0;i<forbiddens.size();++i)//finding first not forbidden colour
    if(!forbiddens[i]){
      colours[curr] = i;
      break;
    }
  
  for(int i=0;i<g[curr].size();++i)//painting neighbouring nodes
    if(colours[g[curr][i]] == -1)
      paint(g[curr][i]);
}

int main(){
  //input ** made n + 1 just for letting it work base 0 or base 1, doesn't matter...
  cin >> n >> m;
  g = vector<vector<int>>(n + 1);
  while(m--){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  colours = vector<int>(g.size());
  for(int i=0;i<colours.size();++i)//set default colour
    colours[i] = -1;
  for(int i=0;i<g.size();++i)//paint all (connected components)
    if(colours[i] == -1)
      paint(i);
  for(int i=0;i<colours.size();++i)
    cout << i << "'s colour is " << colours[i] << "."<< endl;
}
