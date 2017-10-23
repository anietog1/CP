#include <iostream>
#include <string>

using namespace std;
#define MAXN 110
string field;
bool prot[MAXN];
bool important[MAXN];

int main(){
  int t, n;
  cin >> t;
  ++t;
  
  for(int i=1; i < t; ++i){
    cin >> n >> field;
    
    int j = 0, count = 0;
    
    while(j < n){
      if(field[j] == '.'){
	++j;
	++count;
	++j;
      }
      
      ++j;
    }

    cout << "Case " << i << ": " << count << endl;
  }
}
