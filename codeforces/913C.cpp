//Thanks to Um_nik, it's his code, actually -> http://codeforces.com/profile/Um_nik
//Specifically -> http://codeforces.com/contest/913/submission/34010254
#include <iostream>
#include <algorithm>

using namespace std;
#define ull unsigned long long

int main(){
  int n;
  ull L;
  
  cin >> n >> L;
  
  int c[n];
  
  for(int i=0;i<n;++i)
    cin >> c[i];
  
  for(int i=1;i<n;++i)
    c[i] = min(c[i], 2 * c[i-1]);//cost = min(curr, 2_times_prev) -> cuz' 2**i
  
  for(int i=n-2;i>=0;--i)
    c[i] = min(c[i], c[i+1]);//if i can buy more for less, then it costs less :)
  
  ull mincost = 1ULL << 63;
  ull currcost = 0;
  for(int i=n-1;i>=0;--i){
    currcost += c[i] * (L >> i);
    mincost = min(mincost, currcost + c[i]);
    //it'd happen c[i] > L, then i'd be good to check wether it'd be used (c[i]) :)
    L %= 1ULL << i;
  }
  
  cout << min(mincost, currcost) << endl;//is it better exceeding or exact?
}
