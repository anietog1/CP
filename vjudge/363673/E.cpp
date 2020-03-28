#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)

int main() {
  int d[4];

  forn(i, 4) {
    int a, b;
    scanf("%d.%d", &a, &b);
    d[i] = 100 * a + b;
  }
  
  sort(d, d + 4);
  int a, b;
  scanf("%d.%d", &a, &b);

  int goal = 100 * a + b;
  goal *= 3;

  int worst = d[1] + d[2] + d[3];

  if(worst <= goal) {
    cout << "infinite" << endl;
    return 0;
  }

  int best = d[0] + d[1] + d[2];
  if(best > goal) {
    cout << "impossible" << endl;
    return 0;
  }

  for(int i = d[0] + 1; i < d[3]; ++i) {
    int ans = d[2] + d[1] + i;

    if(ans == goal) {
      printf("%.2f\n", i / 100.0);
      return 0;
    }
  }

  printf("%.2f\n", (goal - d[2] - d[1]) / 100.0);
}
