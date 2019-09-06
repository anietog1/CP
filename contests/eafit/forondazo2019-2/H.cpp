#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int N;
  cin >> N;
  while(N--) {
    int d[4];
    cin >> d[0] >> d[1] >> d[2] >> d[3];
    int start = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
    cin >> d[0] >> d[1] >> d[2] >> d[3];
    int end = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];

    int visited[10000] = {};

    int n;
    cin >> n;

    while(n--) {
      cin >> d[0] >> d[1] >> d[2] >> d[3];
      int forbidden = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
      visited[forbidden] = 1;
    }

    queue<int> q;

    if(!visited[start]) {
      visited[start] = 1;
      q.push(start);
    }

    while(!visited[end] && !q.empty()) {
      int curr = q.front();
      q.pop();

      d[0] = curr / 1000;
      d[1] = (curr % 1000) / 100;
      d[2] = (curr % 100) / 10;
      d[3] = curr % 10;

      for(int i = 0; i < 4; ++i) {
        for(int j = -1; j <= 1; j += 2) {
          int tmp[4] = {d[0], d[1], d[2], d[3]};
          tmp[i] = tmp[i] + j;

          if(tmp[i] > 9) tmp[i] = 0;
          else if(tmp[i] < 0) tmp[i] = 9;

          int next = tmp[0] * 1000 + tmp[1] * 100 + tmp[2] * 10 + tmp[3];

          if(!visited[next]) {
            visited[next] = visited[curr] + 1;
            q.push(next);
          }
        }
      }
    }

    if(visited[end] != -1)
      cout << visited[end] - 1 << endl;
    else
      cout << -1 << endl;
  }
}
