#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int T;
  cin >> T;

  while(T--) {
    string x, y;
    cin >> x >> y;

    int indexy = -1, indexx = -1;

    for(int i = 0; i < y.length(); ++i) {
      if(y[y.length() - 1 - i] == '1') {
	indexy = i;
	break;
      }
    }

    for(int i = indexy; i < x.length(); ++i) {
      if(x[x.length() - 1 - i] == '1') {
	indexx = i;
	break;
      }
    }

    int k = 0;

    if(indexx != -1 && indexy != -1) {
      k = indexx - indexy;
    }

    cout << k << endl;
  }
}
