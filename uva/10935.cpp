#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    deque<int> d;
    
    for(int i=1;i<=n;++i)
      d.push_back(i);
    
    vector<int> discarded;
    while(d.size() >= 2){
      discarded.push_back(d.front());
      d.pop_front();//discard "top"
      
      d.push_back(d.front());//pass "top" to "bottom"
      d.pop_front();
    }

    cout << "Discarded cards:";

    if(discarded.size())
      cout << " ";
    
    for(int i=0;i<discarded.size();++i){
      if(i)
	cout << ", ";
      cout << discarded[i];
    }
    cout << endl;
    cout << "Remaining card:" << (n? " ":"") << d.front() << endl;
  }
}
