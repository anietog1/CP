#include <iostream>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
const size_t n = 'Z' - 'A';

string s;

int main(){
  int tc;
  cin >> tc;//disposing testcases input
  
  while(cin >> s){
    bool lvl1[n] = {}, lvl2[n] = {}, lvl3[n] = {};
    int lvl1_count = 0, lvl2_count = 0, lvl3_count = 0;
    
    int size = s.size(), idx;
    
    for(int i=0;i<size;++i){
      idx = s[i] - 'A';
      
      if(i < size - 2 && ! lvl1[idx]){
	lvl1[idx] = true;
	lvl1_count += 1;
      }
      
      if(i > 0 && i < size  - 1 && ! lvl2[idx]){
	lvl2[idx] = true;
	lvl2_count += 1;
      }

      if(i > 1 && !lvl3[idx]){
	lvl3[idx] = true;
	lvl3_count += 1;
      }
    }

    d(lvl1_count);
    d(lvl2_count);
    d(lvl3_count);
    cout << lvl1_count * lvl2_count * lvl3_count << endl;
  }
}
