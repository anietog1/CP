#include <iostream>

using namespace std;
#define MAXN 7500

int coins[] = {1,5,10,25,50}, change[MAXN];

int main(){
  change[0] = 1;
  for(int i=0;i<5;++i)
    for(int j=coins[i];j<MAXN;++j)
      change[j] += change[j - coins[i]];

  int n;
  while(cin >> n)
    cout << change[n] << endl;
}
