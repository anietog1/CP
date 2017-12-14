#include <iostream>
#include <algorithm>
//I saw the code of https://goo.gl/nFcMvm and notice my mistakes :)
//Also read https://goo.gl/w2TPoK
using namespace std;
#define d(x) cout << #x << " = " << x << endl
int tc, n, m[8][8];
bool usedr[8];
int cols[8];
int minv;

//THIS IS TLE CODE
// void calcmin(int coln = 0, int sum = 0){
//   if(coln == n){
//     if(sum < minv)
//       minv = sum;
//     return;
//   }
  
//   int ccol = cols[coln];
  
//   for(int r=0;r<n;++r)
//     if(!usedr[r]){
//       usedr[r] = true;
//       calcmin(coln + 1, sum + m[ccol][r]);
//       usedr[r] = false;
//     }
// }

void calcmin(int coln = 0, int crow = 0, int sum = 0){
  if(coln == n){
    if(sum < minv)
      minv = sum;
    return;
  }
  
  int ccol = cols[coln];
  calcmin(coln + 1, crow + 1, sum + m[ccol][crow]);
}

int main(){
  cin >> tc;
  for(int ctc=1;ctc<=tc;++ctc){
    cin >> n;
    
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
	cin >> m[i][j];
    
    minv = 1 << 29;
    for(int i=0;i<n;++i){
      cols[i] = i;
      usedr[i] = false;
    }
    
    do
      calcmin();
    while(next_permutation(cols, cols + n));
    
    cout << minv << endl;
  }
}
