#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Thanks for ur guidance, xanarry:
//https://github.com/xanarry/ACM-ICPC/blob/master/uva%201594%20Ducci%20Sequence.cpp
//
//Remember, answer what they want you to answer. I didn't really need to know if it was a loop
//'cause it's only going to loop 1000 times -> Complexity O(1000 * 2 * n)
//FOCUS!!

bool counts(int* a, int n){
  for(int i=0;i<n;++i)
    if(a[i])
      return true;
  return false;
}

void transform(int* a, int n){
  int last = abs(a[n-1] - a[0]);
  for(int i=0;i<n-1;++i)
    a[i] = abs(a[i] - a[i + 1]);
  a[n-1] = last;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    
    int nums[n];
    for(int i=0;i<n;++i)
      cin >> nums[i];

    for(int i=0;i<1000 && counts(nums, n);++i)
      transform(nums, n);
    
    if(counts(nums, n))
      cout << "LOOP" << endl;
    else
      cout << "ZERO" << endl;
  }
}
