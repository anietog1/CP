#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string curr;
  while(cin >> curr, curr != "#"){
    if(next_permutation(curr.begin(), curr.end()))
      cout << curr << endl;
    else
      cout << "No Successor" << endl;
  }
}
