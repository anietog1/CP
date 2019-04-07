#include <bits/stdc++.h>

using namespace std;
int n, m;

struct Matrix {
  long long mat[2][2] = {};
};

Matrix matMul(Matrix& a, Matrix& b) {
  Matrix c; int i, j, k;

  for(i = 0; i < 2; ++i)
    for(j = 0; j < 2; ++j)
      for(k = 0; k < 2; ++k) {
        c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        c.mat[i][j] %= 1 << m;
      }

  return c;
}

Matrix matPow(Matrix& base, int p) {
  Matrix ans; int i, j;

  for(i = 0; i < 2; ++i)
    ans.mat[i][i] = 1;

  while(p) {
    if(p & 1) ans = matMul(ans, base);
    base = matMul(base, base);
    p >>= 1;
  }

  return ans;
}

int main() {
  Matrix base;
  base.mat[0][0] = 1;
  base.mat[1][0] = 0;

  while(cin >> n >> m) {
    Matrix multiplier;
    multiplier.mat[0][0] = 1;
    multiplier.mat[0][1] = 1;
    multiplier.mat[1][0] = 1;
    multiplier.mat[1][1] = 0;

    multiplier = matPow(multiplier, n);

    Matrix res = matMul(multiplier, base);
    cout << res.mat[1][0] << endl;    
  }
}
