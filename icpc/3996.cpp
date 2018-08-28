#include <iostream>

using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int nums[10] = {};
    
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
      int curr = i;
      while(curr){
	++nums[curr%10];
	curr/=10;
      }
    }
    
    for(int i=0;i<10;++i)
      cout << (i? " ":"") << nums[i];
    cout << endl;
  }
}
