//first approach was TLE, complexity O(h*w)
//second approach tried with O(w),
//learned from https://tausiq.wordpress.com/2011/04/22/uva-11683-laser-sculpture/ it's possible to solve with stack
#include <iostream>

using namespace std;

#define MAXN 10010

int main(){
  int h, w, curr, last, count;
  
  while(cin >> h >> w){
    if(h == 0 && w == 0)
      break;
    
    cin >> curr;
    last = curr;
    count = 0;
    while(--w){
      cin >> curr;

      if(curr == last)
        continue;
      else if(curr < last)
	last = curr;
      else{//(curr > last)
	count += curr - last;
	last = curr;
      }
    }

    count += h - curr;
    cout << count << endl;
  }

  return 0;
}
