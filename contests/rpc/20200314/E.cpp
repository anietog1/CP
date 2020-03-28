#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << "[DEBUG]" << #x <<  " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define MAXN 5000000

int main() {
  int n, k; cin >> n >> k;

  vector<char> is_real_prime(MAXN+1, true);
  is_real_prime[0] = is_real_prime[1] = false;
  for (int i = 2; i <= MAXN; i++) {
    if (is_real_prime[i] && (long long)i * i <= MAXN) {
      for (int j = i * i; j <= MAXN; j += i)
        is_real_prime[j] = false;
    }
  }

  vector<char> is_fake_prime(MAXN+1, true);
  is_fake_prime[0] = is_fake_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_fake_prime[i] && (long long)i * i <= MAXN) {
      for (int j = i * i; j <= MAXN; j += i)
        is_fake_prime[j] = false;
    }
  }

  int cnt = 0;
  for(int i = n + 1; i <= MAXN; ++i) {
    if(!is_real_prime[i] && is_fake_prime[i]) ++cnt;
    if(cnt == k) {
      cout << i << endl;
      break;
    }
  }
}
