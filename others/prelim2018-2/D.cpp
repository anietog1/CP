#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  ++tc;

  string line;
  getline(cin, line);

  bool flag = false;

  while(tc--) {
    map<string, int> count;
    int n = 0;

    while(getline(cin, line)) {
      if(line.length() == 0) {
        break;
      }

      ++count[line];
      ++n;
    }

    if(n) {
      if(flag) {
        cout << endl;
      } else {
        flag = true;
      }

      for(auto i = count.begin(); i != count.end(); ++i) {
        cout << i->first << " ";
        printf("%.4f\n", 100 * (double(i->second) / n));
      }
    }
  }
}
