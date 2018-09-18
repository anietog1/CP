#include <bits/stdc++.h>

using namespace std;

int main() {
  int a0;

  while(cin >> a0, a0) {
    set<int> nums;

    while(!nums.count(a0)) {
      nums.insert(a0);
      a0 *= a0;
      a0 = (a0 % 1000000) / 100;
    }

    cout << nums.size() << endl;
  }
}
