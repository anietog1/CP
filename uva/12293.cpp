#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(int argc, char** argv, char** env) {
  long n;
  while(cin >> n, n) {
    long i = 1;
    while(i < n) {
      i <<= 1;
      i += 1;
    }
    if(i == n) cout << "Bob" << endl;
    else cout << "Alice" << endl;
  }
}

// The trick is: if k is a winning position, it means after playing you leave
// the other player in a loss position in the range [k/2, k - 1]
// if k is a losing position, it means after playing you can only leave the other
// player in a winning position in the range [k/2, k - 1]
// that's it! if k is a losing position, there'll be another losing position in
// 2 * k + 1, as the possibilities are: [(2 * k + 1) / 2, 2 * k] = [k + 1, 2 * k]
// and in that range there're only winning positions.
