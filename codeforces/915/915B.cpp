#include <iostream>
#include <algorithm>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(){
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  
  int ans = 0;
  
  if(l > 1)
    ans += 1;
  if(r < n)
    ans += 1;
  
  int distl = l > 1? abs(l - pos):0, distr = r < n? abs(r - pos):0;//0 means don't need to go
  
  if(pos > l && pos < r){
    ans += distl + distr;
    ans += min(distl, distr);
  }else{
    ans += max(distr, distl);
  }
  
  cout << ans << endl;
}
