#include <iostream>

using namespace std;
//i watched the video explanation, its awesome ._.
int main(){
  int ans = 0, curr, size;
  cin >> size;

  while(size--){
    cin >> curr;
    ans ^= curr;
  }
  
  cout << ans << endl;
  return 0;
}
