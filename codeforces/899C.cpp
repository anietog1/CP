#include <iostream>
#include <vector>

using namespace std;
#define ull unsigned long long

int main(){
  int n;
  cin >> n;
  
  ull sum = n * (n + 1) / 2;
  ull goal = sum / 2;
  
  cout << sum << endl;
  cout << goal << endl;
  cout << sum % 2 << endl;
  
  vector<int> nums;
  for(int i=n;i>0 && goal;--i){
    if(goal - i >= 0){
      nums.push_back(i);
      goal -= i;
    }
  }
  cout << goal << endl;
  cout << nums.size();
  // for(int i=0;i<nums.size();++i)
  //   cout << " " << nums[i];
  cout << endl;
}
