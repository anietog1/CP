#include <iostream>

using namespace std;

int const MAXN = (1 << 17) + 10;

int n, m, p, b;
int _n;
int a[MAXN];
int t[4 * MAXN];

void build(int v, int tl, int tr, int op) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm, !op);
    build(v*2+1, tm+1, tr, !op);
    if(op)
      t[v] = t[v*2] | t[v*2+1];
    else
      t[v] = t[v*2] ^ t[v*2+1];
  }
}

int query(int v, int tl, int tr, int l, int r, int op) {
  if (l > r)
    return 0;
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;

  if(op)
    return query(v*2, tl, tm, l, min(r, tm), !op)
      | query(v*2+1, tm+1, tr, max(l, tm+1), r, !op);
  else
    return query(v*2, tl, tm, l, min(r, tm), !op)
      ^ query(v*2+1, tm+1, tr, max(l, tm+1), r, !op);
}

void update(int v, int tl, int tr, int pos, int new_val, int op) {
  if (tl == tr) {
    t[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;

    if (pos <= tm)
      update(v*2, tl, tm, pos, new_val, !op);
    else
      update(v*2+1, tm+1, tr, pos, new_val, !op);

    if(op)
      t[v] = t[v*2] | t[v*2+1];
    else
      t[v] = t[v*2] ^ t[v*2+1];
  }
}

int main() {
  cin >> n >> m;
  _n = n;
  n = 1 << n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  build(1, 0, n-1, _n&1);
  while(m--) {
    cin >> p >> b;
    update(1, 0, n-1, p-1, b, _n&1);
    cout << t[1] << endl;
  }
}
