#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m; cin >> n >> m;
  map<int, long long> arr;

  while(m--) {
    int a, b, k; cin >> a >> b >> k;
    arr[a] += k;
    arr[b+1] -= k;
  }

  long long ans=-(1LL<<60);
  long long curr=0;

  for(auto x : arr) {
    curr += x.second;
    ans=max(ans, curr);
  }

  cout << ans << endl;
}
