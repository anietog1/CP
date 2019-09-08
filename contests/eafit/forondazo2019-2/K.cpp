#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int distance(string const& a, string const& b) {
  if(a.size() != b.size()) {
    return -1;
  }

  int count = 0;

  for(int i = 0; i < a.size(); ++i) {
    if(a[i] != b[i]) {
      count++;
    }

    if(count == 2) {
      return -1;
    }
  }

  return count;
}

int main(int argc, char** argv, char** env) {
  int N;
  cin >> N;

  while(N--) {
    map<string, int> smap;
    string imap[200 + 10];

    vector<int> g[200 + 10];

    string str;
    while(cin >> str, str != "*") {
      if(!smap.count(str)) {
        int idx = smap.size();
        smap[str] = idx;
        imap[idx] = str;
      }
    }

    int n = smap.size();

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i != j && distance(imap[i], imap[j]) == 1) {
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }

    getline(cin, str);
    while(getline(cin, str), str != "") {
      istringstream iss(str);
      string a, b;
      iss >> a >> b;

      int visited[n] = {};
      int start = smap[a], end = smap[b];

      queue<int> q;
      q.push(start);

      while(!visited[end] && !q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < g[curr].size(); ++i) {
          int next = g[curr][i];

          if(!visited[next]) {
            visited[next] = visited[curr] + 1;
            q.push(next);
          }
        }
      }

      cout << a << " " << b << " " << visited[end] << endl;
    }

    if(N) {
      cout << endl;
    }
  }
}
