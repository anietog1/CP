//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=640&page=show_problem&problem=868
#include <iostream>

using namespace std;
#define ul unsigned long
#define debug(x) cout << #x << " = " << x << endl

ul pow(int x, int pow){
  ul ret = 1UL;
  
  for(int i = 0; i < pow; ++i)
    ret *= x;

  return ret;
}

int main(){
  int n, d, C, k, degree;
  int anvalues[25];

  cin >> C;
  while(C--){
    cin >> degree;
    for(int i = 0;i <= degree; ++i)
      cin >> anvalues[i];

    cin >> d;
    cin >> k;
    
    n = 1;
    while(k > 0){
      k -= n*d;
      n += 1;
    }
    
    n -= 1;
    ul bm = 0;
    for(int i=0;i <= degree;++i)
      bm += anvalues[i] * pow(n, i);
    
    cout << bm << endl;
  }
  
  return 0;
}
