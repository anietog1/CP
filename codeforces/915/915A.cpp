#include <iostream>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  
  int currbucket, mintime = 1 << 30;
  
  for(int i=0;i<n;++i){
    cin >> currbucket;
    if(k % currbucket == 0 && k / currbucket < mintime)
      mintime = k / currbucket;
  }
  
  cout << mintime << endl;
}
