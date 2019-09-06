#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

bool comp(string const& a, string const& b) {
  string atmp = a;
  string btmp = b;

  for(int i = 0; i < a.size(); ++i) {
    atmp[i] = tolower(atmp[i]);
  }

  for(int i = 0; i < b.size(); ++i) {
    btmp[i] = tolower(btmp[i]);
  }

  return a < b;
}

int main(int argc, char** argv, char** env) {
  int tcs;
  cin >> tcs;

  string line;
  getline(cin, line);
  getline(cin, line);

  while(tcs--) {
    map<string, int> mp;
    int n = 0;

    while(getline(cin, line), line != "") {
      mp[line] += 1;
      ++n;
    }

    string arr[mp.size()];
    int idx = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
      arr[idx++] = it->first;
    }

    sort(arr, arr + mp.size(), comp);

    for(int i = 0; i < mp.size(); ++i) {
      printf("%s %.4f\n", arr[i].c_str(), double(mp[arr[i]] * 100) / n);
    }

    if(tcs) {
      cout << endl;
    }
  }
}
