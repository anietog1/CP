#include <iostream>

using namespace std;

long n, a, b;

void calc(){
  a = b = 0;//cleanup xd
  long curr = 1L, count = 0;
  long lim = 1L << 31;
  
  while(curr < lim && curr <= n){
    if(n & curr){
      if(count == 0)
	a |= curr;
      else
	b |= curr;
      
      count = (count + 1)%2;
    }
    
    curr = curr << 1;
  }
}

int main(){
  cin >> n;
  while(n != 0){
    calc();
    cout << a << " " << b << endl;
    
    cin >> n;
  }
}
