#include <iostream>

using namespace std;
//#define d(x) cout << #x << " = " << x << endl
#define MAXN 100000

int number = 131071;
int pows[MAXN];

int main() {
  pows[0] = 1;
  for(int i = 1; i < MAXN; ++i)
    pows[i] = (pows[i - 1] << 1) % number;

  string str = "", tmp;
  while(cin >> tmp) {
    str.append(tmp);

    if(str[str.length() - 1] == '#') {
      int result = 0;

      str = string(str.rbegin() + 1, str.rend());

      for(int i = 0; i < str.length(); ++i)
        if(str[i] == '1')
          result = (result + pows[i]) % number;

      cout << (result == 0? "YES" : "NO") << endl;
      str = "";
    }
  }
}
