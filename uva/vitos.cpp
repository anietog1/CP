#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int t, r, si;

  cin >> t;
  while(t--){
    cin >> r;
    int rStreet[r];
    for(int i=0; i < r; ++i)
      cin >> rStreet[i];

    int min = 1 << 30;
    for(int i=0;i<r;++i){
      int sum = 0;
      for(int j=0;j<r;++j){
	sum += abs(rStreet[i] - rStreet[j]);
      }

      if(sum < min)
	min = sum;
    }

    cout << min << endl;
    
  }

  return 0;
}
