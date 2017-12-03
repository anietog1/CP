#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAXN 5005
string currstr,  suffixes[MAXN];
int T;

int maxlencommonprefix(string& str1, string& str2){
  int  commonlength = 0;
  int maxlen = max(str1.length(), str2.length());

  for(int j=0;j<maxlen;++j){
    if(str1[j] != str2[j])
      break;
    else
      commonlength += 1;
  }

  return commonlength;  
}

int main(){
  cin >> T;

  while(cin >> currstr){
    for(int i=0;i<currstr.length();++i)
      suffixes[i] = currstr.substr(i);

    sort(suffixes, suffixes + currstr.length());
    
    int maxlen = 0;
    
    for(int i=0;i<currstr.length()-1;++i){
      string &str1 = suffixes[i], &str2 = suffixes[i+1];
      int commonlength = maxlencommonprefix(str1, str2);

      if(commonlength > maxlen)
	maxlen = commonlength;
    }

    cout << maxlen << endl;
  }
}
