#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 100
#define d(x) cout << #x << " = " << x << endl

int main(){
  int n, d, r, m[MAXN], a[MAXN];//morning & afternoon

  while(cin >> n >> d >> r, (n | d | r)){
    for(int i=0;i<n;++i)
      cin >> m[i];

    for(int i=0;i<n;++i)
      cin >> a[i];
    
    sort(m, m + n);
    sort(a, a + n);

    int overtime = 0;
    
    for(int i=0;i<n;++i){
      int curr = m[i] + a[n - 1 - i];//take care here :l
      //      d(curr);
      if(curr > d)
     	overtime += curr - d;
    }

    cout << overtime * r << endl;    
  }
}
