#include <iostream>

using namespace std;
int n;
int coins[22] = {};
long long arr[10010] = {};

int main(){  
  for(int i=0;i<=21;++i)//coins initialization
    coins[i] = i*i*i;
  
  arr[0] = 1LL;
  
  for(int i=1;i<=21;++i)//solving... complex anwer's aren't always the bests :'l
    for(int j=coins[i];j<=10000;++j)
      arr[j] += arr[j - coins[i]];

  while(cin >> n){
    cout << arr[n] << endl;
  }
}
