#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int main(){
  int tc;
  scanf(" %d ", &tc);
  
  for(int i=0;i<tc;++i){
    if(i) puts("");
    string curr;    
    map<string, int> s;
    
    int size = 0;
    while(getline(cin, curr) && curr != ""){
      s[curr] += 1;
      size += 1;
    }
    
    for(map<string, int>::iterator i=s.begin();i!=s.end();++i){
      cout << i->first;
      printf(" %.4f\n", double((i->second) * 100) / size);
    }
  }
}
