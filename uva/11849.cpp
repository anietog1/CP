#include <set>
#include <iostream>

using namespace std;

set<long> cds;

int main(){
  int n, m;
  int common;
  
  cin >> n >> m;
  while(n != 0 && m != 0){
    cds.clear();
    common = 0;
    
    long curr;
    while(n--){
      cin >> curr;
      cds.insert(curr);
    }
    
    while(m--){
      cin >> curr;
      if(cds.count(curr))
	++common;
    }

    cout << common << endl;
    cin >> n >> m;
  }

  return 0;
}
