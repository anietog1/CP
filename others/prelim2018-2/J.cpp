#include <bits/stdc++.h>

using namespace std;

int pow(int x, int n) {
  int res = 1;

  for(int i = 0; i < n; ++i) {
    res *= x;
  }

  return res;
}

int const maxn = 100;
int arr[maxn] = {};

int g_sum(int left, int idx){
  if(left == 0) {
    return 1;
  } else if(left > 0 && arr[idx] > 0) {
    return g_sum(left - arr[idx], idx + 1) + g_sum(left, idx + 1);
  } else {
    return 0;
  }
}

int main() {
  int X, N;
  cin >> X >> N;

  for(int i = 1; (arr[i] = pow(i,N)) <= X; ++i);

  cout << g_sum(X, 1) << endl;
}
