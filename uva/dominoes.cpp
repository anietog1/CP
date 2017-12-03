//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;
#define MAXN 28
#define pii pair<int,int>
//#define debug

bool used[MAXN];
pii does[MAXN];//for do[mino]es
pii done[MAXN];//for done xd
int n, m;

bool can(int idx){
  pii prev = done[idx - 1];
  
  if(idx == n + 1){
    if(done[idx].first == prev.second)
      return true;
    
    return false;
  }
  
  for(int i=0;i<m;++i){
    if(!used[i]){
      pii curr = does[i];
      bool fits = false;

      if(curr.first == prev.second)
	fits = true;
      else{
	swap(curr.first, curr.second);
	if(curr.first == prev.second)
	  fits = true;
      }

      if(fits){
	used[i] = true;
	done[idx] = curr;
	
	if(can(idx + 1))
	  return true;
	else
	  used[i] = false;
      }
    }
  }

  return false;
}

int main(){
  while(cin >> n >> m){
    cin >> done[0].first >> done[0].second;
    cin >> done[n+1].first >> done[n+1].second;
    
    for(int i=0;i<m;++i){
      cin >> does[i].first >> does[i].second;
      used[i] = false;
    }

    bool could = can(1);

#ifdef debug
    for(int i=0;i<=n+1;++i)
      cout << done[i].first << "|" << done[i].second << "->";
    
    cout << endl;
#endif
    
    if(could)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
