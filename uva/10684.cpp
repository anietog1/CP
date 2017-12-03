#include <iostream>

using namespace std;

int main(){
  int n;
  
  cin >> n;
  while(n){
    int max = 0, sum = 0, curr;
    
    for(int i=0;i<n;++i){
      cin >> curr;
      sum += curr;
 
      if(sum < 0)
	sum = 0;
 
      if(sum > max)
	max = sum;
    }
 
    if(max > 0)
      cout << "The maximum winning streak is " << max << "." << endl;
    else
      cout << "Losing streak." << endl;

    cin >> n;
  }
}
