#include <bits/stdc++.h>

using namespace std;

int main() {
  int K;
  cin >> K;
  ++K;

  int msb = 0;

  for(int i = 31; i >= 0; --i) {
    if((1 << i) & K) {
      msb = i;
      break;
    }
  }

  string str;
  str.reserve(msb);

  for(int i = msb - 1; i >= 0; --i) {
    str += (K & (1 << i))? '7' : '4';
  }

  cout << str << endl;
}
