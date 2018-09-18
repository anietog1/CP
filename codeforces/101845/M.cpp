#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  long double acum = 0;

  if(k > m) {
    acum += m;
  } else if(k == m) {
    acum += k - 1;
    acum += ((long double) 1) / (n + 1);
  } else {//k < m
    acum += k - 1;
    m -= (k - 1);
    acum += ((long double) m) / (n + m);
  }

  printf("%.9Lf\n", acum / k);
}
