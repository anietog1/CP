#include <bits/stdc++.h>

using namespace std;

int main() {
  double x1, y1, x2, y2, cmd, enf;
  double pi = acos(-1);

  while(cin >> x1 >> y1 >> x2 >> y2 >> cmd >> enf) {
    double ab = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    cmd = pi * (cmd / 180);
    enf = pi * (enf / 180);
    printf("%.3f\n", ab * (1 / tan(cmd) + 1 / tan(enf)));
  }
}
