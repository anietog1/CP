#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int N;

  while(cin >> N, N != 0) {
    int arr[N];

    while(cin >> arr[0], arr[0] != 0) {
      for(int i = 1; i < N; ++i) cin >> arr[i];

      stack<int> s;
      int j = 0;
      for(int i = 1; i <= N; ++i) {
        s.push(i);

        while(!s.empty() && s.top() == arr[j]) {
          s.pop();
          ++j;
        }
      }

      if(s.empty()) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }

    cout << endl;
  }
}
