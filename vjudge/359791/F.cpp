#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;

  while(n--) {
    string s; cin >> s;

    stack<char> st;
    int i;
    for(i = 0; i < s.size(); ++i) {
      char c = s[i];
      if(c == '[' || c == '{' || c == '(') st.push(c);
      if(c == ']')
        if(st.size() > 0 && st.top() == '[') st.pop();
        else break;
      if(c == '}')
        if(st.size() > 0 && st.top() == '{') st.pop();
        else break;
      if(c == ')')
        if(st.size() > 0 && st.top() == '(') st.pop();
        else break;
    }

    if(st.size() != 0 || i != s.size())
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
