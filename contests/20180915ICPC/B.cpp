#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main() {
  ull L, n, d;
  while(cin >> L >> n >> d, L | n | d) {
    ull min_num = 1ULL << 62, min_den = 1;

    for(ull b = 1; b <= n; ++b) {
      ull a = 1 + (d * b - 1) / L;// a >= d * b / L (ceil)

      ull curr_num = a * L;
      ull curr_den = b;

      // (c_num / c_den < m_num / m_den) -> (c_num * m_den) < (m_num * c_den)
      if(curr_num * min_den < min_num * curr_den) {
        min_num = curr_num;
        min_den = curr_den;
      }
    }

    ull my_gcd = __gcd(min_num, min_den);
    cout << (min_num / my_gcd) << "/" << (min_den / my_gcd) << endl;
  }
}
