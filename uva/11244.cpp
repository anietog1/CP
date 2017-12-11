#include <iostream>
#include <string>

using namespace std;
#define maxn 101

int r, c;
string map[maxn];
bool visited[maxn][maxn];

int cs(int i, int j){
  if(i < 0 || j < 0 || i >= r || j >= c || visited[i][j] || map[i][j] != '*')
    return 0;

  visited[i][j] = true;

  return
    1
    + cs(i-1,j-1)
    + cs(i-1,j)
    + cs(i-1,j+1)
    + cs(i,j-1)
    + cs(i, j+1)
    + cs(i+1,j-1)
    + cs(i+1,j)
    + cs(i+1,j+1);
}

int main(){
  while(cin >> r >> c, (r | c)){
    for(int i=0;i<r;++i){
      cin >> map[i];
      
      for(int j=0;j<c;++j)
	visited[i][j] = false;
    }
    
    int sum = 0;
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
	if(!visited[i][j] && map[i][j] == '*')
	  if(cs(i, j) == 1)
	    ++sum;
    
    cout << sum << endl;
  }
}
