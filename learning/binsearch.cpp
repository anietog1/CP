#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool contains(vector<int>& arr, int n){
  int ulim = arr.size();
  int llim = 0;

  while(ulim != llim){
    int pos = (ulim + llim)/2;
    cout << arr[pos] << endl;
    
    if(arr[pos] > n)
      ulim = pos;
    else if(arr[pos] < n)
      llim = pos;
    else
      return true;
  }
  
  return false;
}

int main(){
  vector<int> arr
    = {1,2,10,3,4,5,6,321,7,123,8,9,23,10,11,1203,99,92,7412,12,13,14,15,16,17};

  sort(arr.begin(), arr.end());
  
  int input;
  while(cin >> input)
    cout << contains(arr, input) << endl;
}
