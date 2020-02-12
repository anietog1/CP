#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x " = " << x << endl

#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, j, k) for(int i = j; i <= k; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const ll INF = LONG_LONG_MAX;

int main() {
  //fast i/o: do not combine iostream with stdio
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  //input replacements
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //some tricks
  //biggest first. replace int with type
  priority_queue<int, vector<int>, greater<int>> q;
  string str = to_string(10);
  int x = stoi("123");
  float f = stof("1.112");
  //mems
  int src[10], dst[10];
  memset(src, 0, 10 * sizeof(int));
  memcpy(dst, src, 10 * sizeof(int));
  //sorts
  vi vec;
  sort(src, src + 10);
  sort(vec.rbegin(), vec.rend());//reverse order
  //traversing
  for(auto x : vec);
}
