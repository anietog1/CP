#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
#define pii pair<int, int>

bool cmp(pii const& a, pii const& b){
  return a.second > b.second;
}

int main(){
  int n;
  cin >> n;
  pii arr[n];
  
  for(int i=0;i<n;++i)
    cin >> arr[i].first;//rem vol
  
  for(int i=0;i<n;++i)
    cin >> arr[i].second;//tot vol
  
  sort(arr, arr + n, cmp);
  
  int capacity = arr[0].second + arr[1].second;
  
  for(int i=0;i<n && capacity>=0;++i)
    capacity -= arr[i].first;
  
  if(capacity >= 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
