#include <iostream>

using namespace std;

int main(){
  int n, h;
  cin >> n >> h;
  int p[n];
  int minw = 0;
  for(int i=0;i<n;++i){
    cin >> p[i];
    if(p[i] <= h)
      minw += 1;
    else
      minw += 2;
  }
  cout << minw << endl;
}
