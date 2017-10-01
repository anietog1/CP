#include <cstdio>

using namespace std;
#define MAXN 1000
char word[MAXN];
int times[MAXN];

void clear(){
  for(int i='a'; i <= 'z'; ++i)
    times[i] = 0;
}

int count(){
  clear();
  int max1 = 0, max2 = 0, n = 0;
  
  for(int i=0; word[i] != 0; ++i){
    int curr = ++times[word[i]];
    ++n;
    if(curr > max1){
      max1 = curr;
    }else if(curr > max2){
      max2 = curr;
    }
  }
  
  return n - max1 - max2;
}

int main(){
  while(scanf("%s", word) == 1){
    printf("%d\n", count());
  }
  
  return 0;
}
