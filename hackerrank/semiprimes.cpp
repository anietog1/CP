#include <vector>
#include <bitset>
#include <cstdio>
#include <cmath>
//#define debug
using namespace std;

const unsigned long long LIM = 10000010;
bitset<LIM> sv;
vector<int> ps;

void sieve(){
  sv.set();
  
  sv[0] = sv[1] = 0;
  for(int i = 2; i < sv.size(); ++i){
    if(sv[i]){
      ps.push_back(i);
      for(int j = i*i; j < LIM; j += i){
	sv[j] = false;
      }
    }
  }
}

int nSps(int limit){
  int start = (int) sqrt(limit);
  int i = 0;
  while(ps[i] << 1 <= limit) ++i;

  int count = 0;

  for(int j=0; j<i; ++j){
    for(int k=j; k < i; ++k){
      if(ps[j]*ps[k] > limit) break;
      ++count;
    }
  }
  
  return count;
}

int main(){
  int t, n;
  sieve();
#ifdef debug
  for(int i=0; i<ps.size(); ++i)
    printf("%i ", ps[i]);
#endif
  
  scanf("%i", &t);
  
  while(t){
    scanf("%i", &n);
    printf("%i\n", nSps(n));
    --t;
  }
}
