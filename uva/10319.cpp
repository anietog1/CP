// DID NOT PASS AT FIRST, SINCE I TRIED TO HARDCODE EVERY SINGLE EDGE
// I READ https://github.com/Diusrex/UVA-Solutions/blob/master/10319%20Manhattan.cpp
// AND DISCOVERED HOW TO MAKE IT MORE MODULAR :) BASICALLY ALWAYS NEGATE ADDING/SUBSTRACTING
// UVa 10319 - Manhattan
#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

vector<int> g[200];
vector<int> invg[200];

bool visited[200];
int comp[200], com;
vector<int> order;

int av(int x) {
  return 50 + x;
}

int _not(int x) {
  if(x > 100) return x - 100;
  else return x + 100;
}

void dfs1(int x) {
  visited[x] = true;
  for(int v : g[x])
    if(!visited[v])
      dfs1(v);
  order.push_back(x);
}

void dfs2(int x) {
  comp[x] = com;
  for(int v : invg[x])
    if(comp[v] == -1)
      dfs2(v);
}

void _or(int x, int y) {
  g[_not(x)].push_back(y);
  if(x != y)
    g[_not(y)].push_back(x);
}

int main(int argc, char** argv, char** env) {
  int n; cin >> n;

  while(n--) {
    for(int i = 0; i < 200; ++i) {
      g[i].clear();
      invg[i].clear();
      for(int i = 0; i < 200; ++i)
        visited[i] = false;
      com = 0;
      for(int i = 0; i < 200; ++i)
        comp[i] = -1;
    }

    int S, A, m; cin >> S >> A >> m;

    while(m--) {
      int s1, a1, s2, a2; cin >> s1 >> a1 >> s2 >> a2;
      a1 = av(a1), a2 = av(a2);

      if(s1 == s2) {
        if(a1 < a2)
          _or(s1, s1);
        else
          _or(_not(s1), _not(s1));
      } else if(a1 == a2) {
        if(s1 < s2)
          _or(a1, a1);
        else
          _or(_not(a1), _not(a1));
      } else {
        if(a1 > a2)
          s1 = _not(s1), s2 = _not(s2);

        if(s1 > s2)
          a1 = _not(a1), a2 = _not(a2);

        _or(a1, a2);
        _or(s1, s2);
        _or(a1, s1);
        _or(a2, s2);
      }
    }

    for(int i = 1; i <= S; ++i) {
      if(!visited[i])
        dfs1(i);
      if(!visited[_not(i)])
        dfs1(_not(i));
    }

    for(int i = 1; i <= A; ++i) {
      if(!visited[av(i)])
        dfs1(av(i));
      if(!visited[_not(av(i))])
        dfs1(_not(av(i)));
    }

    reverse(order.begin(), order.end());

    for(int i = 0; i < 200; ++i) {
      for(int v : g[i])
        invg[v].push_back(i);
    }

    for(int i = 0; i < order.size(); ++i) {
      if(comp[order[i]] == -1)
        dfs2(order[i]), ++com;
    }

    bool fail = false;

    for(int i = 1; i <= S; ++i)
      if(comp[i] == comp[_not(i)])
        fail = true;

    for(int i = 1; i <= A; ++i)
      if(comp[av(i)] == comp[_not(av(i))])
        fail = true;

    if(fail) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}
