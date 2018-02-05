#include <iostream>
#include <cctype>
#include <vector>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
//Lesson taken from:
//NOTICE U HAVE TO UNDERSTAND WHAT THEY WANT YOU TO SOLVE!!!!
//U don't have to find the longest wff, u have to form the longest possible wff!!
//http://mypaper.pchome.com.tw/zerojudge/post/1324858968

int main(){
  string in;
  
  while(getline(cin, in), in != "0"){
    vector<char> vars, kans;
    int nots=0;
    
    for(int i=0;i<in.size();++i){
      if(isupper(in[i])){
	if(in[i] == 'N'){
	  ++nots;
	}else{
	  kans.push_back(in[i]);
	}
      }else{
	vars.push_back(in[i]);
      }
    }
    
    if(vars.size()){
      while(nots--)
	cout << 'N';
      
      for(int i=0,j=1;i<kans.size()&&j<vars.size();++i,++j)
	cout << kans[i] << vars[j];
      cout << vars[0] << endl;
    }else
      cout << "no WFF possible" << endl;
  }
}
