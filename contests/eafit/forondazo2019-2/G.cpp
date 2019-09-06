#include <bits/stdc++.h>

using namespace std;
#define MAXCHAR 256
#define d(x) cout << #x << " = " << x << endl

int main(int argc, char** argv, char** env) {
  int N;
  cin >> N;

  while(N--) {
    int K;
    cin >> K;

    int prices[MAXCHAR] = {};

    while(K--) {
      char c;
      cin >> c >> prices[c];
    }

    int M;
    cin >> M;
    string tmp; getline(cin, tmp);

    int reps[MAXCHAR] = {};

    while(M--) {
      string line;
      getline(cin, line);
      for(int i = 0; i < line.size(); ++i) {
        reps[line[i]] += 1;
      }
    }

    int ans = 0;
    for(int i = 0; i < MAXCHAR; ++i) {
      ans += reps[i] * prices[i];
    }

    int dols = ans / 100, cents = ans % 100;

    if(cents < 10) {
      printf("%d.0%d$\n", dols, cents);
    } else {
      printf("%d.%d$\n", dols, cents);
    }
  }
}
