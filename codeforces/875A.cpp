#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  vector<int> ans;
  
  cin >> n;
  for(int i = n - 9*33;i<=n;++i){
    if(i < 0)
      i = 0;
    
    int x = i;
    int sum = x;
    
    while(x){
      sum += x%10;
      x /= 10;
    }
    
    if(sum == n)
      ans.push_back(i);
  }
  
  cout << ans.size() << endl;
  for(int i=0;i<ans.size();++i)
    cout << ans[i] << endl;
}
