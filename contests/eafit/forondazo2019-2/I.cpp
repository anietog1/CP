#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  long fib[55];
  fib[0] = 0;
  fib[1] = 1;

  for(int i = 2; i <= 53; ++i) fib[i] = fib[i - 1] + fib[i - 2];

  int n;
  while(cin >> n, n) {
    cout << fib[n + 1] << endl;
  }
}
