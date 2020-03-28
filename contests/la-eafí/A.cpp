#include <bits/stdc++.h>

using namespace std;

struct node {
  int next[10];
  bool isLast;
  node() {
    for(int i = 0; i < 10; ++i) next[i] = -1;
    isLast = false;
  }
};

node trie[1000000];
int _size = 1;

void add(string const& str) {
  int traveler = 0;
  for(int i = 0; i < str.size(); ++i) {
    int idx = str[i] - '0';
    if(trie[traveler].next[idx] == -1)
      trie[traveler].next[idx] = _size++;
    traveler = trie[traveler].next[idx];
  }
  trie[traveler].isLast = true;
}

string getMax(string const& str) {
  string ans = "00000000000000000000";
  int traveler = 0;
  for(int i = 0; i < str.size(); ++i) {
    int idx = str[i] - '0';
  }
}

string getMin(string const& str) {
  string ans = "99999999999999999999";
}

void normalize(string& str) {
  string temp;
  temp.append(20 - str.size(), '0');
  str = temp + str;
}

int main(int argc, char** argv, char** env) {
  int n; cin >> n;
  string str; cin >> str; normalize(str);
  string _min = "99999999999999999999", _max = "00000000000000000000";
  add(str);
  while(n--) {
    cin >> str; normalize(str);
    _min = min(_min, getMin(str));
    _max = max(_max, getMax(str));
    add(str);
  }
  cout << _min << " " << _max << endl;
}
