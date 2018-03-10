#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
unordered_map<int, int> counts;

int main(){
  int curr;
  while(cin >> curr){
    nums.push_back(curr);
    counts[curr] += 1;
  }

  for(int i=0;i<nums.size();++i){
    int& count = counts[nums[i]];
    if(count){
      cout << nums[i] << " " << count << endl;
      count = 0;
    }
  }
}
