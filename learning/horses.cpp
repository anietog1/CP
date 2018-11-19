#include <bits/stdc++.h>
//O((n**2)!)

using namespace std;
#define n 8
#define pii pair<int, int>
//#define d(x) cout << #x << " = " << x << endl

bool visited[n][n] = {};
pii movements[n*n] = {};

bool valid(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < n;
}

bool visit(int i, int j, int count){
  visited[i][j] = true;
  movements[count] = pii(i, j);
#ifdef d
  d(count);
#endif
  if(count == n * n - 1)//This is the last one
    return true;
  
  int moves = 8;
  pii next[moves] = {//Possible moves ordered clockwise
    pii(i+1, j-2),
    pii(i-1, j-2),
    
    pii(i-2, j-1),
    pii(i-2, j+1),
    
    pii(i-1, j+2),
    pii(i+1, j+2),
    
    pii(i+2, j+1),
    pii(i+2, j-1)
  };
  
  for(int i=0;i<moves;++i){
    int nexti = next[i].first, nextj = next[i].second;
    if(valid(nexti, nextj) && !visited[nexti][nextj])
      if(visit(nexti, nextj, count + 1))
	return true;
  }
  
  visited[i][j] = false;
  return false;
}

ostream& operator<<(ostream& o, pii pos){
  return o << (char)(pos.first + 'A') << pos.second + 1;
}

int main(){
  visit(0, 0, 0);
  for(int i=0;i<n*n;++i){
    cout << movements[i] << endl;
  }
}
