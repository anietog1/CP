#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << "[DEBUG]" << #x <<  " = " << x << endl
#define PI acos(-1)
#define EPS 1e-9

int main() {
  int L, W, H; cin >> L >> W >> H;
  int x0, y0, a; cin >> x0 >> y0 >> a;

  double ang = (a * PI) / 180;
  double x1 = x0 + H * cos(ang);
  double y1 = y0 + H * sin(ang);

  if(x1 >= -EPS && x1 <= W + EPS && y1 >= -EPS && y1 <= L + EPS)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
