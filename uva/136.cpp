#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
#define ull unsigned long long
//Important: every ugly number comes from a ugly number

int main(){
  vector<ull> ugsorder;
  set<ull> ugscount;
  
  priority_queue<ull, vector<ull>, greater<ull>> q;
  q.push(1);
  
  while(ugscount.size() < 1500){
    ull curr = q.top();
    q.pop();
    
    if(!ugscount.count(curr)){
      ugsorder.push_back(curr), ugscount.insert(curr);
      
      q.push(curr*2), q.push(curr*3), q.push(curr*5);
    }
  }
  
  sort(ugsorder.begin(), ugsorder.end());
  
  cout << "The 1500'th ugly number is " << ugsorder[1500 - 1] << "." << endl;
}
