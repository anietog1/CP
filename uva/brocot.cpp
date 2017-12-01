#include <iostream>

using namespace std;

int main(){
  long long n, cnum, cden;
  string str;
  
  cin >> n;
  while(cin >> str){
    cnum = cden = 1LL;
    long long lnum = 0LL, lden = 1LL, unum = 1LL, uden = 0LL;
    
    for(int i=0;i<str.length();++i){
      if(str[i] == 'L'){
	unum = cnum;
	uden = cden;
      } else {
	lnum = cnum;
	lden = cden;
      }
      
      cnum = lnum + unum;
      cden = lden + uden;
    }
    
    cout << cnum << "/" << cden << endl;
  }
}
