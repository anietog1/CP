#include <iostream>
#include <stack>

using namespace std;

struct passed{
  int k, x, y;

  passed(int k, int x, int y):
    k(k), x(x), y(y){}
  
  void print(){
    cout << "1/" << k << " = 1/" << x << " + 1/" << y << endl;
  }
};

int main(){
  int k;
  while(cin >> k){
    stack<passed> s;

    for(int y = 2*k; y > k; --y){//from 2*n 'til n
      int up = y*k;
      int down = y - k;

      if(up%down == 0){
	s.push(passed(k, up/down, y));
      }
    }

    cout << s.size() << endl;
    while(!s.empty()){
      s.top().print();
      s.pop();
    }
  }
}
