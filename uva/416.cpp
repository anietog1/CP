#include <iostream>
#include <string>

using namespace std;

int n;
string led[10];
bool matches;
bool burned[7];

string const number[10] =
  {
    "YYYYYYN",
    "NYYNNNN",
    "YYNYYNY",
    "YYYYNNY",
    "NYYNNYY",
    "YNYYNYY",
    "YNYYYYY",
    "YYYNNNN",
    "YYYYYYY",
    "YYYYNYY"
  };

void calcfrom(int currn, int ledn = 0){
  if(ledn == n)
    matches = true;
  else if(currn >= 0){
    bool can = true;
    
    for(int i=0;i<7;++i){
      char curr = led[ledn][i];
      char expected = number[currn][i];
      
      if((burned[i] && curr == 'Y') || (curr == 'Y' && expected == 'N')){
	can = false;
	break;
      }
      
      if(curr == 'N' && expected == 'Y')
	burned[i] = true;
    }
    
    if(can)
      calcfrom(currn - 1, ledn + 1);
  }
}

void countdown(){
  for(int i=n-1;i<=9;++i){
    matches = false;

    for(int i=0;i<7;++i)
      burned[i] = false;
    
    calcfrom(i);
    
    if(matches)
      break;
  }
}

int main(){
  while(cin >> n, n){
    for(int i=0;i<n;++i)
      cin >> led[i];
    
    countdown();
    
    if(matches)
      cout << "MATCH" << endl;
    else
      cout << "MISMATCH" << endl;
  }
}
