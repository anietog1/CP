#include <bits/stdc++.h>

using namespace std;

string const ne = "non-existent"
  , rec = "recessive"
  , dom = "dominant"
  , wtf = "";

map<string, string> gen;
map<string, vector<string>> parents;

string check(string name) {
  if(gen[name] != wtf) return gen[name];
  else {
    string p1 = parents[name][0], p2 = parents[name][1];
    p1 = check(p1), p2 = check(p2);

    gen[name] = ne;

    if(p1 != ne && p2 != ne
       || p1 == dom
       || p2 == dom)
      gen[name] = rec;

    if(p1 == dom && p2 == dom
       || p1 == dom && p2 == rec
       || p1 == rec && p2 == dom)
      gen[name] = dom;

    return gen[name];
  }
}

int main(int argc, char** argv, char** env) {
  int n; cin >> n;

  while(n--) {
    string s1, s2; cin >> s1 >> s2;
    if(s2 == ne ||
       s2 == rec ||
       s2 == dom)
      gen[s1] = s2;
    else {
      gen[s2] = wtf;
      parents[s2].push_back(s1);
    }
  }

  for(auto it = gen.begin(); it != gen.end(); ++it) {
    check(it->first);
  }

  vector<string> names;

  for(auto it = gen.begin(); it != gen.end(); ++it) {
    names.push_back(it->first);
  }

  sort(names.begin(), names.end(),
       [](string a, string b) {
         for(int i = 0; i < a.size(); ++i) a[i] = tolower(a[i]);
         for(int i = 0; i < b.size(); ++i) b[i] = tolower(b[i]);
         return a < b;
       });

  for(int i = 0; i < names.size(); ++i) {
    cout << names[i] << " " << gen[names[i]] << endl;
  }
}
