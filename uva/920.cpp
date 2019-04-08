#include <bits/stdc++.h>

using namespace std;
#define MAXN 105

struct point {
  double x, y;
};

struct line {
  double a, b, c;
};

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

point intersect(line l1, line l2) {
  point p;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  p.y = -(l2.a * p.x + l2.c);
  return p;
}

line ptol(point p1, point p2) {
  line l;
  l.a = -(p1.y - p2.y) / (p1.x - p2.x);
  l.b = 1.0;
  l.c = -(l.a * p1.x) - p1.y;
  return l;
}

point points[MAXN];

int main() {
  int C;
  cin >> C;
  while(C--) {
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
      cin >> points[i].x >> points[i].y;
    }

    auto cmp = [](point a, point b) { return a.x < b.x; };
    sort(points, points + N, cmp);

    double ans = 0;
    point last = points[N - 1];
    for(int i = N - 2; i >= 0; --i) {
      point curr = points[i];

      if(curr.y >= last.y) {
        line m = ptol(curr, points[i + 1]);
        point tmp = last;
        tmp.x = -1.0;
        line hor = ptol(last, tmp);
        ans += dist(curr, intersect(m, hor));
        last = curr;
      }
    }

    printf("%.2f\n", ans);
  }
}
