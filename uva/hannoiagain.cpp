//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=645&page=show_problem&problem=1217
#include <iostream>

using namespace std;
int n, t, maxval, turn;
int arr[55];

bool ubicar(int val){
  for(int i=0;i<n;++i){
    if(arr[i]){
      if(arr[i] + val == turn*turn){
	arr[i] = val;
	return true;
      } else if(arr[i] + val == (turn + 1)*(turn + 1)) {
	++turn;
	arr[i] = val;
	return true;
      }
    } else {
      arr[i] = val;
      return true;
    }
  }

  return false;
}

void fill(){
  maxval = 1;
  turn = 1;
  
  while(maxval < 1 << 30 && ubicar(maxval))
    ++maxval;

  if(maxval == 1 << 30)
    maxval = -1;
  else
    --maxval;
}

int main(){
  cin >> t;
  while(cin >> n){
    for(int i=0;i<n;++i)
      arr[i] = 0;
    
    fill();
    cout << maxval << endl;
  }
}
