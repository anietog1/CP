#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(int argc, char** argv, char** env) {
  int b;
  cin >> b;

  for(int r = 1; r <= b; ++r) {
    int s;
    cin >> s;

    int maxsum = 0;
    int maxi = 1, maxj = 1;

    int currsum = 0;
    int curri = 1, currj = 2;

    while(currj <= s) {
      int n;
      cin >> n;

      currsum += n;

      if(currsum > maxsum || currsum == maxsum && (currj - curri) > (maxj - maxi)) {
        maxsum = currsum;
        maxi = curri;
        maxj = currj;
      }

      if(currsum < 0) {
        currsum = 0;
        curri = currj;
      }

      ++currj;
    }

    if(maxsum <= 0) {
      cout << "Route " << r << " has no nice parts" << endl;
    } else {
      cout << "The nicest part of route " << r << " is between stops " << maxi << " and " << maxj << endl;
    }
  }
}
