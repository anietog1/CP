#include <iostream>

using namespace std;
#define maxn (1000 + 20)
#define d(x) cout << #x << " = " << x << endl
#define darr(arr, n) {cout << #arr << ":";for(int i = 0; i < n; ++i) cout << " " << arr[i]; cout << endl;}

int main() {
    int tc; cin >> tc;

    for(int ctc = 1; ctc <= tc; ++ctc){
      cout << "Case " << ctc << ". ";

      int N; cin >> N;
      int h[N], w[N];
      for(int i = 0; i < N; ++i) cin >> h[i];
      for(int i = 0; i < N; ++i) cin >> w[i];

      int lis[N] = {};
      for(int i = 0; i < N; ++i) {
        lis[i] = w[i];

        for(int j = i - 1; j >= 0; --j) {
          if(h[i] > h[j]) {
            lis[i] = max(lis[i], lis[j] + w[i]);
          }
        }
      }

      int lds[N] = {};
      for(int i = 0; i < N; ++i) {
        lds[i] = w[i];

        for(int j = i - 1; j >= 0; --j) {
          if(h[i] < h[j]) {
            lds[i] = max(lds[i], lds[j] + w[i]);
          }
        }
      }

      int A = 0, B = 0;
      for(int i = 0; i < N; ++i) {
        A = max(A, lis[i]);
        B = max(B, lds[i]);
      }

      if(A >= B) {
        cout << "Increasing (" << A << "). Decreasing (" << B << ")." << endl;
      } else {
        cout << "Decreasing (" << B << "). Increasing (" << A << ")." << endl;
      }
    }
}
