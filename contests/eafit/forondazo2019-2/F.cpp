#include <bits/stdc++.h>

using namespace std;

int p[30000];
int n;

int find(int x) {
  if(x == p[x]) return x;
  else return p[x] = find(p[x]);
}

int _not(int x) {
  return x + n;
}

void join(int x, int y) {
  int px = find(x), py = find(y);
  p[px] = p[py] = min(px, py);
}

void setFriends(int x, int y) {
  join(x, y);
  join(_not(x), _not(y));
}

void setEnemies(int x, int y) {
  join(_not(x), y);
  join(x, _not(y));
}

bool areFriends(int x, int y) {
  int px = find(x), py = find(y);
  return px == py;
}

bool areEnemies(int x, int y) {
  int px = find(x), notpy = find(_not(y));
  return px == notpy;
}

int main(int argc, char** argv, char** env) {
  cin >> n;

  for(int i = 0; i < n; ++i) {
    p[i] = i;
    p[_not(i)] = _not(i);
  }

  int c, x, y;
  while(cin >> c >> x >> y, c | x | y) {
    if(c == 1) {
      if(!areEnemies(x, y)) {
        setFriends(x, y);
      } else {
        cout << -1 << endl;
      }
    } else if(c == 2) {
      if(!areFriends(x, y)) {
        setEnemies(x, y);
      } else {
        cout << -1 << endl;
      }
    } else if(c == 3) {
      cout << areFriends(x, y) << endl;
    } else if(c == 4) {
      cout << areEnemies(x, y) << endl;
    }
  }
}
