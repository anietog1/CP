//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=626&page=show_problem&problem=535
#include <iostream>
#include <algorithm>

using namespace std;

void printbits(int n){ 
  for(int i=31;i>=0;--i){
    int x = (n & (1 << i)) != 0;
    if(i%8 == 7)
      cout << " ";
    cout << x;
  }

  cout << endl;
}

unsigned int bytenum(int n, int i){
  int base = i*8;
  int end = base + 8;
  int x = 0;
  
  for(int j=base;j<end;++j)
    x |= n & (1 << j);
  
  return x;
}

int main(){
  int n, m;
  
  while(cin >> n){
    m = 0;
    //    printbits(n);

    m |= bytenum(n, 0) << 24;
    //    printbits(m);
    m |= bytenum(n, 1) << 8;
    //    printbits(m);
    m |= bytenum(n, 2) >> 8;
    //    printbits(m);
    m |= bytenum(n, 3) >> 24;
    //    printbits(m);

    cout << n << " converts to " << m << endl;
  }
}
