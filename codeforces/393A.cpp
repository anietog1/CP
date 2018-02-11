#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string s;
  int arr['z' + 1] = {};
  cin >> s;
  for(int i=0;i<s.size();++i)
    ++arr[s[i]];
  cout << min((arr['n']-1)/2, min(arr['i'], min(arr['e']/3, arr['t']))) << endl; 
}
