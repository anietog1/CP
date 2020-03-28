#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)

int main() {
  int n; cin >> n;
  string s; cin >> s;

  while(true){
    char maxl=-1;
    int maxi=-1;

    forn(i,s.size()) {
      if(s[i]>maxl){
        if((i>0&&s[i]-1==s[i-1])||(i<n-1&&s[i]-1==s[i+1])) {
          maxl=s[i];
          maxi=i;
        }
      }
    }

    if(maxl!=-1){
      s=s.substr(0,maxi)+s.substr(maxi+1);
    } else break;
  }

  cout << n-s.size() << endl;
}
