#include <cstdio>

using namespace std;
//Numberphile did all the job :'v
//https://www.youtube.com/watch?v=uCsD3ZGzMgE

int n, pos;

int isOn(int a, int pos){
  return a & (1 << pos);
}

void turnOf(int &a, int pos){
  a = a ^ (1 << pos);
}

void calc(){
  //remove last power of two
  for(int i=31; i >= 0; --i){
    if(isOn(n, i)){
      turnOf(n, i);
      break;
    }
  }
  
  //pos = 2*l + 1
  pos = (n << 1) + 1;
}

int main(){
  scanf(" %d", &n);
  calc();
  printf("%d\n", pos);
  
  return 0;
}
