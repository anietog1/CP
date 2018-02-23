#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(){
  int n, m;
  cin >> n >> m;

  char map[n][m];
  int moves[4] = {0, 1, 2, 3};
  string instrs;
  
  for(int i=0;i<n;++i)
    cin >> map[i];
  cin >> instrs;
  
  int x, y, ways = 0;
  
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      if(map[i][j] == 'S'){
	y = i, x = j;
	break;
      }
  
  do{
    int currx = x, curry = y;
    for(int i=0;i<instrs.size();++i){
      int currmv = moves[instrs[i] - '0'];
      
      switch(currmv){
      case 0:
     	currx += 1;
     	break;
      case 1:
     	currx -= 1;
     	break;
      case 2:
     	curry += 1;
     	break;
      case 3:
     	curry -= 1;
     	break;
      }
      
      if(curry < 0 || curry >= n ||
     	 currx < 0 || currx >= m ||
     	 map[curry][currx] == '#')
     	break;
      else if(map[curry][currx] == 'E'){
     	++ways;
     	break;
      }
    }
  }while(next_permutation(moves, moves + 4));
  cout << ways << endl;
}
