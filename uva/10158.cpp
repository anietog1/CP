#include <bits/stdc++.h>

using namespace std;
int p[100000];

int find(int x) {
  return p[x] == x? x : p[x] = find(p[x]);
}

void join(int x, int y) {
  x = find(x), y = find(y);
  if(x != y) p[x] = y;
}

int neg(int x) {
  return 50000 + x;
}

bool areFriends(int x, int y) {
  return find(x) == find(y) || find(neg(x)) == find(neg(y));
}

bool areEnemies(int x, int y) {
  return find(x) == find(neg(y)) || find(neg(x)) == find(y);
}

void setFriends(int x, int y) {
  join(x, y);
  join(neg(x), neg(y));
}

void setEnemies(int x, int y) {
  join(x, neg(y));
  join(neg(x), y);
}

int main(int argc, char** argv, char** env) {
  int n; cin >> n;
  for(int i = 0; i < n; ++i) p[i] = i, p[neg(i)] = neg(i);

  int c, x, y; cin >> c >> x >> y;
  while(!(c == 0 && x == 0 && y == 0)) {
    switch(c) {
    case 1:
      if(areEnemies(x, y)) cout << -1 << endl;
      else setFriends(x, y);
      break;
    case 2:
      if(areFriends(x, y)) cout << -1 << endl;
      else setEnemies(x, y);
      break;
    case 3:
      cout << areFriends(x, y) << endl;
      break;
    case 4:
      cout << areEnemies(x, y) << endl;
      break;
    }

    cin >> c >> x >> y;
  }
}
