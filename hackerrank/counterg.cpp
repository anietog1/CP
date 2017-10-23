#include <iostream>
#include <climits>

using namespace std;
#define ull unsigned long long

bool isPow2(ull n){
  ull curr = (1ULL << 63);
  
  while(curr != 0){
    if(n == curr)
      return true;
    
    curr = curr >> 1;
  }
  
  return false;
}

ull getHighestPow2(ull n){
  ull curr = (1ULL << 63);

  while(!(curr & n)){
    curr = curr >> 1;
  }
  
  return curr;
}

int play(ull n){
  int turn = 0;//0 loui, 1 rich
  
  while(n > 1){
    if(isPow2(n)){
      n = n >> 1;
    }else{
      n = n - getHighestPow2(n);
    }

    ++turn;
  }
  
  return turn % 2;//if 0, means lou's turn
}

int main(){
  int t;
  unsigned long long n;
  cin >> t;
  
  while(t--){
    cin >> n;
    int winner = play(n);
    if(winner == 0)
      cout << "Richard" << endl;
    else
      cout << "Louise" << endl;
  }

  return 0;
}
