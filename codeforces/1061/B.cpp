#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  int n, m;
  cin >> n >> m;

  int stacks[n];
  for(int i = 0; i < n; ++i) cin >> stacks[i];

  sort(stacks, stacks + n);
  int side_view[n] = {1};

  for(int i = 1; i < n; ++i)
    side_view[i] = side_view[i - 1] + (stacks[i] > side_view[i - 1]);

  int max_height = stacks[n - 1];

  long long needed = n + (max_height - side_view[n - 1]);
  long long total = 0;
  for(int i = 0; i < n; ++i) total += stacks[i];

  cout << total - needed << endl;
}
