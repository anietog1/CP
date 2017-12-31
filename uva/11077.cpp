#include <iostream>
//After some tries, I read this code http://www.cnblogs.com/lidaxin/p/5130696.html

using namespace std;
typedef unsigned long long ull;

int main(){
  ull n, k, arr[23][23] = {};
  
  arr[1][0] = 1;
  
  for(n=2;n<=21;++n)
    for(k=0;k<n;++k){
      arr[n][k] = arr[n-1][k];//sum of k moves for n - 1
      if(k)
	arr[n][k] += arr[n-1][k-1] * (n - 1);//k moves for (n-1,k-1) times n-1 -> permutation
    }
  
  while(cin >> n >> k, (n | k))
    cout << arr[n][k] << endl;
}
