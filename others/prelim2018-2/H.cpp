#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define d(x) cout << #x << " = " << x << endl

int main() {
  ull n;
  cin >> n;

  int msb = 63;

  while(msb > 0) {
    if((1ULL << msb) & n) {
      break;
    }
    --msb;
  }

  ull acum = 1ULL;

  for(int i = 0; i < msb; ++i) {
    if((1ULL << i) & n) {
      //NOTHING
    } else {
      acum <<= 1;
    }
  }

  cout << acum << endl;
}
