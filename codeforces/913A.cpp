#include <iostream>

using namespace std;
#define ull unsigned long long

int main(){
  ull n, m;
  cin >> n >> m;
  
  ull pow2 = 1;
  for(int i=0;i<n;++i){
    pow2 <<= 1;
    if(pow2 > m)
      break;
  }
  
  cout << m % pow2 << endl;
}
