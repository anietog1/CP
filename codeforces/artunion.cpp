#include <iostream>

using namespace std;
int t[50000][5] = {}, count[50000] = {};
int m, n;

void work(){
  for(int i=1;i<m;++i)//base artist summary
    t[i][0] += t[i-1][0];

  for(int j=1;j<n;++j)//base time summary
    t[0][j] += t[0][j-1];
  
  for(int j=1;j<n;++j){//simple dp :), time = max(prevartist + curr, prevcurr + curr)
    for(int i=1;i<m;++i){
      int base = max(t[i][j-1], t[i-1][j]);
      
      t[i][j] += base;
    }
  }
}

int main(){
  cin >> m >> n;
  for(int i=0;i<m;++i)
    for(int j=0;j<n;++j)
      cin >> t[i][j];

  work();
  
  for(int i=0;i<m;++i)
    cout << t[i][n - 1] << " ";
}
