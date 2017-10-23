#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
#define MAXN 25005

vector<int> nums;

int main(){
  int n;
  nums.reserve(MAXN);
  
  scanf(" %d", &n);
  while(n != 0){
    nums.clear();
    
    while(n){
      int curr;
      scanf(" %d", &curr);
      nums.push_back(curr);
      --n;
    }

    sort(nums.begin(), nums.end());

    // for(int i=0; i < nums.size(); ++i)
    //   printf("%d", nums[i]);
    // printf("\n");
    
    int moda,
      last = nums[0],
      curr,
      countModa = 0,
      currCount = 0;
    
    for(int i=0; i < nums.size(); ++i){
      curr = nums[i];
      if(curr == last){
	currCount += 1;
      }else{
	if(currCount > countModa){
	  moda = last;
	  countModa = currCount;
	}
	
	last = curr;
	currCount = 1;
      }
    }

    if(currCount > countModa)//Por si falto el ultimo
      moda = last;
    
    printf("%d\n", moda);
    scanf(" %d", &n);
  }
  
  return 0;
}
