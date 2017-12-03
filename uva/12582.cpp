#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 30
#define d(x) cout << #x << " = " << x << endl;

int t, idx;
string walk;
vector<int> g[MAXN];

void clear(){
  idx = 0;
  for(int i=0;i<MAXN;++i)
    g[i].clear();
}

int next(){
  return walk[idx++] - 'A';
}

void traverse(int curr){
  int nextnode;

  while((nextnode = next()) != curr){
    //d(nextnode);
    g[nextnode].push_back(curr);
    g[curr].push_back(nextnode);
    traverse(nextnode);
  }
}

int main(){
  cin >> t;
  for(int turn = 1; turn <= t; ++turn){
    cin >> walk;
    clear();
    traverse(next());

    cout << "Case " << turn << endl;
    
    for(int i=0;i<MAXN;++i){
      int size = g[i].size();
      
      if(size)
	cout << (char)(i + 'A') << " = " << size << endl;
    }
  }
}
