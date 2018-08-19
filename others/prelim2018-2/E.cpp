#include <bits/stdc++.h>

using namespace std;

int main() {
  int maxn = 51;
  long long arr[maxn];
  arr[0] = 1;
  arr[1] = 1;

  for(int i = 2; i < maxn; ++i) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  int n;
  while(cin >> n, n) {
    cout << arr[n] << endl;
  }
}
