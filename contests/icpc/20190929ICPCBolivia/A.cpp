#include <iostream>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)
#define MOD (1000000007)

void multiply(long a[27][27], long b[27][27]) {
  long tmp[27][27] = {};
  forn(i, 27)
    forn(j, 27)
      forn(k, 27)
        tmp[i][j] = (tmp[i][j] + (a[i][k]%MOD)*(b[k][j]%MOD))%MOD;
  forn(i, 27)
    forn(j, 27)
      a[i][j] = tmp[i][j];
}

int main() {
  int T; cin >> T;
  while(T--) {
    string S; cin >> S;
    int K, N; cin >> K >> N;

    long cnts[27] = {};
    forn(i, S.size()) ++cnts[S[i]-'a'];

    long mat[27][27] = {};
    bool visited[27] = {};
    while(K--) {
      char c; cin >> c;
      string Pc; cin >> Pc;
      visited[c-'a']=true;
      forn(i, Pc.size()) {
        ++mat[Pc[i]-'a'][c-'a'];
      }
    }

    forn(i, 27) if(!visited[i]) mat[i][i]=1;

    long tmat[27][27] = {};
    forn(i, 27) forn(j, 27) tmat[i][j] = mat[i][j];
    while(N > 2) {
      multiply(tmat, tmat);
      if(N & 1) multiply(tmat, mat);
      N >>= 1;
    }

    long ans[27] = {};
    forn(i, 27)
      forn(j, 27)
        ans[i] = (ans[i] + (tmat[i][j]%MOD)*(cnts[j]%MOD))%MOD;

    long last_ans = 0;
    forn(i, 27)
      last_ans = (last_ans + ans[i])%MOD;

    cout << last_ans << endl;
  }
}
