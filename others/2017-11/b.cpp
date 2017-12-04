#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 100010
#define M 1000000007
#define d(x) cout << #x << " = " << x << endl;

int n, p[MAXN], c[MAXN];

int fact(int n, int m){
  int ans = 1;

  while(n){
    ans = (ans * n) % m;
    --n;
  }
  
  return ans;
}

int main(){
  cin >> n;
  
  for(int i=0;i<n;++i)
    cin >> p[i];
  
  for(int i=0;i<n;++i)
    cin >> c[i];

  sort(p, p + n);
  sort(c, c + n);
  
  int ways = fact(n, M);
  
  for(int i=0;i<n;++i){
    int good = i;
    
    for(int j=i;j<n;++j){
      if(c[i] < p[j])
	break;
      
      ++good;
    }
    
    ways = ways - ( fact(n - i - 1, M) * (n - good) ) % M;

    if(ways < 0)
      break;
  }
  
  if(ways < 0)
    cout << 0 << endl;
  else
    cout << ways << endl;
}
