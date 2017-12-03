#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 1010

struct soldier{
  int b, j;
};

bool compare(soldier& a, soldier& b){
  return a.j > b.j;
}

int n, b, j, turn;
soldier squad[MAXN];

int main(){
  cin >> n;
  turn = 1;
  
  while(n){
    for(int i=0;i<n;++i)
      cin >> squad[i].b >> squad[i].j;
    
    sort(squad, squad + n, compare);
    
    int btime = 0, totaltime = 0;

    for(int i=0;i<n;++i){
      soldier curr = squad[i];
      btime += curr.b;
      
      totaltime = max(totaltime, btime + curr.j);
    }
    
    cout << "Case " << turn++ << ": " << totaltime << endl;
    cin >> n;
  }
};
