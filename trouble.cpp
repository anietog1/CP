#include <bits/stdc++.h>

using namespace std;
#define maxn 100000
#define pii pair<int, int>

int T, N;
int evens[maxn], nums[maxn], odds[maxn], nevens, nodds, idx;

//Always starts with evens
int main(){
  cin >> T;
  
  for(int tc=1;tc<=T;++tc){
    cin >> N;
    nevens = nodds = 0;
    idx = -1;
    
    for(int i=0;i<N;++i){
      if(i & 1){
	cin >> odds[nodds++];
      }else{
	cin >> evens[nevens++];
      }
    }
    
    sort(evens, evens + nevens);
    sort(odds, odds + nodds);
    
    for(int i=0;i<nodds;++i){
      nums[i << 1] = evens[i];
      nums[(i << 1) + 1] = odds[i];
    }
    
    if(nevens > nodds){
      nums[N - 1] = evens[nevens - 1];
    }

    for(int i=0;i<N-1;++i){
      if(nums[i] > nums[i + 1]){
	idx = i;
	break;
      }
    }
    
    if(idx == -1)
      cout << "Case #" << tc << ": " << "OK" << endl;
    else
      cout << "Case #" << tc << ": " << idx << endl;

    //-------------------- DEBUG ---------------
    for(int i=0;i<nevens;++i)
      cout << evens[i] << " ";
    cout << endl;

    
    for(int i=0;i<nodds;++i)
      cout << odds[i] << " ";
    cout << endl;
    
    for(int i=0;i<N;++i)
      cout << nums[i] << " ";
    cout << endl;
  }
}
