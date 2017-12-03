#include <cstdio>

using namespace std;

int main(){
  int nDigits;
  while(scanf("%d", &nDigits) == 1){
    switch(nDigits){
    case 2:
      for(int i=0; i < 100; ++i){
	int a = i/10, b = i % 10;
	if((a+b)*(a+b) == i){
	  printf("%01d%01d\n", a, b);
	}
      }
      break;
    case 4:
      for(int i=0; i < 10000; ++i){
	int a = i/100, b = i % 100;
	if((a+b)*(a+b) == i){
	  printf("%02d%02d\n", a, b);
	}
      }
      break;
    case 6:
      for(int i=0; i < 1000000; ++i){
	int a = i/1000, b = i % 1000;
	if((a+b)*(a+b) == i){
	  printf("%03d%03d\n", a, b);
	}
      }
      break;
    case 8:
      for(int i=0; i < 100000000; ++i){
	int a = i/10000, b = i % 10000;
	if((a+b)*(a+b) == i){
	  printf("%04d%04d\n", a, b);
	}
      }
      break;
    }
  }
  return 0;
}
