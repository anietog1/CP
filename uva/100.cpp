#include <bits/stdc++.h>

using namespace std;

int main(){
  int i, j;
  while(cin >> i >> j){
    int maxcycle = 0, first = min(i, j), last = max(i, j);
    for(int k=first;k<=last;++k){
      unsigned int n = k;
      int cycle = 1;
      
      while(n != 1){
	if(n&1)
	  n = 3*n + 1;
	else
	  n = n >> 1;
	++cycle;
      }
      
      maxcycle = max(maxcycle, cycle);
    }
    
    cout << i << " " << j << " " << maxcycle << endl;
  }
}
