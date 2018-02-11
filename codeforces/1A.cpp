#include <iostream>

using namespace std;

int main(){
  unsigned long long n, m, a;
  cin >> n >> m >> a;
  unsigned long long divn = n / a, divm = m / a;
  cout << ((divn*a==n)? divn:divn+1) * ((divm*a==m)? divm:divm+1) << endl;
}
