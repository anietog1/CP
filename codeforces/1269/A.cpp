#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int n; cin >> n;
  int a, b;
  b = 2 * 2 * 3 * 3 * 2 * 2 * 3 * 3;
  a = n + b;
  while((b % 3 != 0 && b % 2 != 0) || (a % 3 != 0 && a % 2 != 0)) ++a, ++b;
  cout << a << " " << b << endl;
}
