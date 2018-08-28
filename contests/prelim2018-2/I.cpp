#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, ll> arr;

  while(m--) {
    int a, b;
    ll k;
    cin >> a >> b >> k;

    arr[a] += k;
    arr[b + 1] -= k;
  }

  ll max_sum = 0;
  ll curr_sum = 0;

  for(auto i = arr.begin(); i != arr.end(); ++i) {
    curr_sum += i->second;
    max_sum = max(max_sum, curr_sum);
  }

  cout << max_sum << endl;
}
