#include <iostream>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x << " = " << x << endl

int main() {
  int t; cin >> t;
  while(t--) {
    int x, y, a, b; cin >> x >> y >> a >> b;

    int px = x, py = y;

    int s = 0;
    while(px < py) {
      int pmid = (px + py) / 2;
      int sx = (pmid - px) / a;
      int sy = (py - pmid) / b;

      if(sx < sy) {
        px = px + sx * a;
        py = py - sx * b;
        s += sx;
      } else {
        px = px + sy * a;
        py = py - sy * b;
        s += sy;
      }

      if(sx == 0 || sy == 0) {
        s += 1;
        px += a;
        py -= b;
      }
    }

    if(px == py) cout << s << endl;
    else cout << -1 << endl;
  }
}
