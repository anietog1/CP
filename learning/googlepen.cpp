#include <cstdio>

using namespace std;
#define MAXN 100
// -- for 2x2, | for 1x2
char sq[MAXN];
int n;

void drawSquares(int idx){
  if(n - idx == 0){
    printf("%s\n",sq);
  }else if(n - idx == 1){
    sq[idx] = '|';
    printf("%s\n",sq);
  }else{
    sq[idx] = '|';
    drawSquares(idx + 1);
    sq[idx] = sq[idx+1] = '-';
    drawSquares(idx + 2);
  }
}

void clear(int n){
  sq[n] = 0;
}

int main(){
  while(scanf("%d", &n) == 1){
    clear(n);
    drawSquares(0);
  }
}
