#include <iostream>
#include <string>

using namespace std;
#define MAXN 100

int m, n;
string map[MAXN];

void incr(int i, int j){
  if(i < 0 || i >= m || j < 0 || j >= n || map[i][j] == '*')
    return;
  
  map[i][j] += 1;
}

void minearound(int i, int j){
  incr(i - 1, j - 1);
  incr(i - 1, j);
  incr(i  - 1, j + 1);

  incr(i, j - 1);
  incr(i, j);
  incr(i, j + 1);
  
  incr(i + 1, j - 1);
  incr(i + 1, j);
  incr(i + 1, j + 1);
}

int main(){
  int tc = 0;
  
  while(cin >> m >> n, (m | n)){
    for(int i=0;i<m;++i)
      cin >> map[i];

    for(int i=0;i<m;++i)
      for(int j=0;j<n;++j)
	if(map[i][j] == '.')
	  map[i][j] = '0';

    for(int i=0;i<m;++i)
      for(int j=0;j<n;++j)
	if(map[i][j] == '*')
	  minearound(i, j);

    if(tc)
      cout << endl;
    cout << "Field #" << ++tc << ":" << endl;
    for(int i=0;i<m;++i)
      cout << map[i] << endl;
  }
}
