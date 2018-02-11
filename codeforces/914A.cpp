#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, arr[1001];
  cin >> n;
  for(int i=0;i<n;++i)
    cin >> arr[i];
  sort(arr, arr + n);
  for(int i=n-1;i>=0;--i){
    double val;
    if(arr[i] < 0)
      goto shit;
    val = sqrt(arr[i]);
    if(val != int(val)){
    shit:
      cout << arr[i] << endl;
      break;
    }
  }
}
