#include <bits/stdc++.h>
using namespace std;
#define d(x) cout << #x << " = " << x << endl
#define maxn 1000000
vector<int> primes;

void buildsieve(){
  bitset<maxn+1> sieve;
  sieve.set();
  for(int i=3;i*i<=maxn;i+=2)
    if(sieve[i])
      for(int j=i*i;j<=maxn;j+=i)
	sieve[j] = false;
  primes.push_back(2);
  for(int i=3;i<=maxn;i+=2)
    if(sieve[i])
      primes.push_back(i);
}

int nextprime(int n){
  int l=0, r=primes.size(), i=(l+r)/2;
  while(l < r && primes[i] != n){
    if(primes[i] < n){
      l = i + 1;
    }else if(primes[i] > n){
      r = i - 1;
    }
    
    i=(l + r)/2;
  }
  
  return primes[i] < n ? primes[i+1]:primes[i];
}

int main(){
  buildsieve();
  int n, m;
  cin >> n >> m;
  int matrix[n][m], mins[n][m];
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j){
      cin >> matrix[i][j];
      mins[i][j] = nextprime(matrix[i][j]) - matrix[i][j];
    }
  int minmin = 1 << 30;
  for(int i=0;i<n;++i){
    int sum = 0;
    for(int j=0;j<m;++j)
      sum += mins[i][j];
    minmin = min(minmin, sum);
  }
  for(int i=0;i<m;++i){
    int sum = 0;
    for(int j=0;j<n;++j)
      sum += mins[j][i];
    minmin = min(minmin, sum);
  }
  cout << minmin << endl;
}
