#include <bits/stdc++.h>

using namespace std;
int const maxn = 2000 + 5;

unsigned long long in[maxn];
unsigned long long out[maxn];

int main() {
  int N, M;
  cin >> N >> M;

  for(int i = 0; i < N; ++i) {
    cin >> in[i];
  }

  for(int i = 0; i < M; ++i) {
    cin >> out[i];
  }

  map<unsigned long long, int> count;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if(in[i] <= out[j]) {
        ++count[out[j] - in[i]];
      }
    }
  }

  int m_freq = 0;
  int ans;

  for(auto i = count.begin(); i != count.end(); ++i) {
    if(i->second > m_freq) {
      ans = i->first;
      m_freq = i->second;
    }
  }

  cout << ans << endl;
}
