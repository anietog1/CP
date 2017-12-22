#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
#define MAXN 1030

int map[MAXN][MAXN];
int tc, d, n, sze;

void incr(int x, int y){
  if(x <= 0 || y <= 0 || x > 1025 || y > 1025)
    return;
  
  map[x][y] += sze;
}

void clear(){
  for(int i=1;i<=1025;++i)
    for(int j=1;j<=1025;++j)
      map[i][j] = 0;
}

int main(){
  cin >> tc;
  while(tc--){
    cin >> d >> n;
    clear();
    
    while(n--){
      int x, y;
      cin >> x >> y >> sze;
      
      incr(x, y);
      
      for(int i=1;i<=d;++i){//diagonals
	incr(x-i, y-i);
	incr(x-i, y+i);
	incr(x+i, y-i);
	incr(x+i, y+i);
      }


      for(int i=1;i<=d;++i){//axis
	incr(x-i, y);
	incr(x+i,y);
	incr(x,y-i);
	incr(x,y+i);
      }
      
      for(int i=1;i<=d;++i){//holes :)
       	for(int j=1;j<i;++j){//ud holes
	  incr(x-j, y-i);
	  incr(x+j, y-i);
	  incr(x-j, y+i);
	  incr(x+j, y+i);
       	}
	
	for(int j=1;j<i;++j){//lr holes
	  incr(x-i, y-j);
	  incr(x-i, y+j);
	  incr(x+i, y-j);
	  incr(x+i, y+j);  
	}
      }
    }

    // for(int i=1;i<20;++i){
    //   for(int j=1;j<20;++j)
    //  	cout << map[i][j] << " ";
    //   cout << endl;
    // }
    
    int rats = 0, x = 0, y = 0;
    for(int i=1;i<=1025;++i)
      for(int j=1;j<=1025;++j)
	if(map[i][j] > rats){
	  rats = map[i][j];
	  x = i;
	  y = j;
	}
    
    cout << x << " " << y << " " << rats << endl;
  }
}
