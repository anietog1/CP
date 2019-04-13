#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << endl
//Take care with parameters: xE[-100k, 100k], yE[0, 100k], zE[0, 100k].
//You wasted time searching for an answer for yE[-100k, 100k]
//Take care with datatypes

struct point {
  int x, y, z;
};

bool aligned(point a, point b) {
  long long x1 = a.x, y1 = a.y;
  long long x2 = b.x, y2 = b.y;
  long long m1 = x1 * y2;
  long long m2 = x2 * y1;
  return m1 == m2;
}

bool cmp(point a, point b) {
  long long x1 = a.x, y1 = a.y;
  long long x2 = b.x, y2 = b.y;
  long long m1 = x1 * y2;
  long long m2 = x2 * y1;

  if(m1 == m2)
    return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;

  return m1 < m2;
}

int main() {
  int N;
  int cnt = 1;

  while(cin >> N && N) {
    point lights[N];

    for(int i = 0; i < N; ++i)
      cin >> lights[i].x >> lights[i].y >> lights[i].z;

    sort(lights, lights + N, cmp);

    pair<int, int> h_lights[N];
    int count = 0;

    int max_z = lights[0].z;
    for(int i = 1; i < N; ++i) {
      if(aligned(lights[i - 1], lights[i])) {
        if(max_z >= lights[i].z)
          h_lights[count++] = make_pair(lights[i].x, lights[i].y);
        else max_z = max(max_z, lights[i].z);
      } else max_z = lights[i].z;
    }

    cout << "Data set " << cnt++ << ":" << endl;
    if(count) {
      cout << "Some lights are not visible:" << endl;

      sort(h_lights, h_lights + count);

      for(int i = 0; i < count; ++i)
        cout << "x = " << h_lights[i].first
             << ", y = " << h_lights[i].second
             << (i != count - 1? ";" : ".") << endl;
    } else cout << "All the lights are visible." << endl;
  }
}
