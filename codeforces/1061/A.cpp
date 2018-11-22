#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, S;
  cin >> n >> S;

  if(S % n) {
    cout << S / n + 1 << endl;
  } else {
    cout << S / n << endl;
  }
}
