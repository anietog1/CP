#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(int argc, char** argv, char** env) {
  int n;
  cin >> n;
  while(n--) {
    string str;
    cin >> str;

    stack<int> s;
    int count = 0;

    for(int i = 0; i < str.size(); ++i) {
      if(str[i] == '\\') {
        s.push(i);
      } else if(str[i] == '/') {
        if(!s.empty()) {
          count += i - s.top();
          s.pop();
        }
      }
    }

    cout << count << endl;
  }
}
