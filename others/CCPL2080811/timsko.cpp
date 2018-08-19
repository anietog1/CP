#include <bits/stdc++.h>

using namespace std;

int main() {
  int M, N, K;

  cin >> M >> N >> K
    while(K) {
      if(M > N * 2) {
        --M;
      } else {
        --N;
      }

      --K;
    }

  cout << min(M / 2, N) << endl;
}
