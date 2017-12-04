#include <iostream>

using namespace std;
int const INF = 1 << 26;

int main(){
  int T, R, H;
  while(cin >> T >> R >> H){
    int t[T][R], r[R][H], h[H][T];
    
    for(int i=0;i<T;++i){
      int val;
      cin >> val;
      
      for(int j=0;j<R;++j){
	bool cant;
	cin >> cant;
	
	if(cant)
	  t[i][j] = INF;
	else
	  t[i][j] = val;
      }
    }
    
    for(int i=0;i<R;++i){
      int val;
      cin >> val;
      
      for(int j=0;j<H;++j){
	bool cant;
	cin >> cant;

	if(cant)
	  r[i][j] = INF;
	else
	  r[i][j] = val;
      }
    }
    
    for(int i=0;i<H;++i){
      int val;
      cin >> val;

      for(int j=0;j<T;++j){
	bool cant;
	cin >> cant;

	if(cant)
	  h[i][j] = INF;
	else
	  h[i][j] = val;
      }
    }
    
    int min = INF;
    int mt, mr, mh;
    
    for(int i=0;i<T;++i){
      for(int j=0;j<R;++j){
	for(int k=0;k<H;++k){
	  int sum = t[i][j] + r[j][k] + h[k][i];
	  
	  if(sum < min){
	    min = sum;
	    mt = i;
	    mr = j;
	    mh = k;
	  }
	}
      }
    }
    
    
    if(min < INF)
      cout << mt << " " << mr << " " << mh << ":" << min << endl;
    else
      cout << "Don't get married!" << endl;
  }
}
