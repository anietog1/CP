#include <iostream>
#include <algorithm>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(){
  int const n = 5;
  int tc = 0;
  string puzzle[n];
  string path;

  getline(cin, path);
  while((puzzle[0] = path) != "Z"){
    if(tc)
      cout << endl;
    cout << "Puzzle #" <<  ++tc << ":" << endl;    

    int y, x;
    
    for(int i=1;i<n;++i)
      getline(cin, puzzle[i]);
    
    for(int i=0;i<n;++i){
      if(puzzle[i].size() < n)
	puzzle[i] += ' ';
      
      for(int j=0;j<n;++j)
	if(puzzle[i][j] == ' '){
	  y = i, x = j;
	  break;
	}
    }
    
    bool valid = true, nextpath = true;
    
    while(getline(cin, path), nextpath){
      if(path[path.size() - 1] == '0')
	nextpath = false;
      
      if(valid)
	for(int i=0;i<path.size() && valid;++i){
	  switch(path[i]){
	  case 'A':
	    if(y > 0)
	      swap(puzzle[y][x], puzzle[y-1][x]);
	    else
	      valid = false;
	    
	    --y;
	    break;
	  case 'B':
	    if(y < n - 1)
	      swap(puzzle[y][x], puzzle[y+1][x]);
	    else
	      valid = false;
	    
	    ++y;
	    break;
	  case 'R':
	    if(x < n - 1)
	      swap(puzzle[y][x], puzzle[y][x+1]);
	    else
	      valid = false;
	    
	    ++x;
	    break;
	  case 'L':
	    if(x > 0)
	      swap(puzzle[y][x], puzzle[y][x-1]);
	    else
	      valid = false;
	    
	    --x;
	    break;
	  }
	}
    }
    
    if(valid)
      for(int i=0;i<n;++i){
	for(int j=0;j<n;++j){
	  if(j)
	    cout << " ";
	  cout << puzzle[i][j];
	}
	cout << endl;
      }
    else
      cout << "This puzzle has no final configuration." << endl;
  }
}
