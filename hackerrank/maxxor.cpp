#include <iostream>

using namespace std;

int maxXor(int l, int r) {
  // int max = 0;
  
  // for(int i = l; i <= (l + r)/2; ++i){
  //   for(int j = r; j >= (l + r)/2; --j){
  //     int curr = i ^ j;
      
  //     if( curr > max ){
  // 	max = curr;
  //     }
  //   }
  // }
  // DUNNO WHY MY FIRST IMPLEMENTATION DOESNT WORK ALTHOUGH ITS A COMPLETE SEARCH

  //explained by kevinchacon at discussion
  //U find the MSB, then the best case is all bits differ from there :)

  int b = l ^ r;

  int msbpos = 32 - __builtin_clz(b);

  return (1 << msbpos) - 1;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res << endl;
    
    return 0;
}
