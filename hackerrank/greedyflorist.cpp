//https://www.hackerrank.com/challenges/greedy-florist/problem
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n, k, c[1000010];

int main(){
  cin >> n >> k;

  for(int i=0;i<n;++i)
    cin >> c[i];

  sort(c, c+n, greater<int>());
       
  int min = 0, x = 0;
  
  for(int i=0;i<n;++i){
    if(i%k == 0)//aqui ya se hizo (x + 1), ya que empieza en 1, no en 0
      x += 1;
    
    min += x * c[i];
  }

  cout << min << endl;
}
