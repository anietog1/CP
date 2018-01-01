#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(){
  ull x;
  while(cin >> x)
    cout << x*x*(x+1)*(x+1)/4 << endl;//Remember this things exist :c
}

// ull ans[50001] = {};

// ull pow(ull base, int exp){
//   ull ans = 1;
  
//   for(int i=0;i<exp;++i)
//     ans *= base;
  
//   return ans;
// }

// int main(){
//   for(int i=1;i<=50000;++i)
//     ans[i] = ans[i-1] + pow(i, 3);
  
//   int x;
//   while(cin >> x)
//     cout << ans[x] << endl;
// }
