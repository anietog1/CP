#include <iostream>
using namespace std;
int main(){
  int n, c=0;
  cin >> n;
  for(int i=1;i*i<=n;++i)
    c += n/i-(i-1);
  cout << c << endl;
}
