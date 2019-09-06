#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main() {
  int T;
  cin >> T;

  for(int tc = 1; tc <= T; ++tc) {
    int N;
    cin >> N;

    string str;
    cin >> str;

    int i = 0, count = 0;
    while(i < N) {
      if(str[i] == '#') {
        ++i;
      } else if(str[i] == '.') {
        count += 1;
        i += 3;
      }
    }

    cout << "Case " << tc << ": " << count << endl;
  }
}
