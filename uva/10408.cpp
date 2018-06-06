#include <bits/stdc++.h>

using namespace std;
#define MAXN 1010
#define pii pair<int, int>

int gcd(int a, int b) {
  return b==0? a:gcd(b, a%b);
}

int main() {
  int n, k;
  while(cin >> n >> k) {
    pii arr[n * n];
    arr[0] = pii(1,1);
    int size = 1;
    for(int den=2;den<=n;++den)
      for(int num=1;num<den;++num)
        if(gcd(num, den) == 1)
          arr[size++] = pii(num, den);
    sort(arr, arr + size, [](pii a, pii b) -> bool {
        return a.first * b.second < b.first * a.second;
      });
    cout << arr[k-1].first << "/" << arr[k-1].second << endl;
  }
}
