#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long r;

  while(cin >> n >> r) {
    //input
    int mappings[n + 1];
    for(int i = 1; i <= n; ++i) {
      cin >> mappings[i];
    }

    //setup
    int cards[n + 1];
    for(int i = 1; i <= n; ++i) {
      cards[i] = i;
    }

    //cycle finding
    int cycles[n + 1] = {};

    vector<int> records[n + 1];
    for(int i = 1; i <= n; ++i) {
      records[i].reserve(n);
      records[i].push_back(i);
    }

    for(int i = 1; i <= n; ++i) {
      for(int c_round = 1; cycles[i] == 0; ++c_round) {
        cards[i] = mappings[cards[i]];

        if(cards[i] == i) {
          cycles[i] = c_round;
        } else {
          records[i].push_back(cards[i]);
        }
      }
    }

    //output
    cout << records[1][r % cycles[1]];
    for(int i = 2; i <= n; ++i) {
      cout << " " << records[i][r % cycles[i]];
    }
    cout << endl;
  }
}
