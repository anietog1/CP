#include <iostream>
#include <string>

using namespace std;
#define MAXN  11
#define pii pair<int, int>

int r, c, start;
string map[MAXN];
int steps, loop;

void walk(){
  bool exited = false;
  steps = loop = 0;

  int i = 0, j = start;
  int walk[r][c] = {};
  
  while(!exited && ! loop){
    if(i < 0 || j < 0 || i >= r || j >= c){
      exited = true;
      break;
    }else if(walk[i][j]){
      loop = steps - walk[i][j] + 1;
      steps = walk[i][j] - 1;
      break;
    }
    
    char move = map[i][j];
    walk[i][j] = ++steps;
    
    switch(move){
    case 'W':
      j -= 1;
      break;
    case 'E':
      j += 1;
      break;
    case 'S':
      i += 1;
      break;
    case 'N':
      i -= 1;
      break;
    }
  }
}

int main(){
  while(cin >> r >> c >> start, r | c | start){
    start -= 1;//just for using 0 index
    
    for(int i=0;i<r;++i)
      cin >> map[i];

    walk();

    if(loop)
      cout << steps << " step(s) before a loop of " << loop << " step(s)" << endl;
    else
      cout << steps << " step(s) to exit" << endl;
  }
}
