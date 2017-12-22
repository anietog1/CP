#include <iostream>
#include <string>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
int main(){
  int tc;
  cin >> tc;
  
  for(int ctc=1;ctc<=tc;++ctc){
    if(ctc > 1)
      cout << endl;
    cout << "Case " << ctc << ":" << endl;
    
    int n;
    cin >> n;
    string txt[n];
    getline(cin, txt[0]);
    for(int i=0;i<n;++i)
      getline(cin, txt[i]);
    
    for(int i=0;i<n;++i){
      bool prevspace = false;
      
      for(int j=0;j<txt[i].length();++j){
	if(txt[i][j] == ' '){
	  if(prevspace)
	    continue;
	  
	  cout << ' ';
	  prevspace = true;
	}else{
	  prevspace = false;
	  cout << txt[i][j];
	}
      }
      
      cout << endl;
    }
  }
}
