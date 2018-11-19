#include <cstdio>
#include <utility>
/**
 * Problemas que hubo:
 * Hacerla llegar hasta el final
 * Testeo imcompleto -> dudas sobre el ultimo caso de prueba
 */
using namespace std;

int n;

void print(int bd[]){
  printf("Imprimiendo...\n");
  for(int i=0; i< n; ++i)
    printf("row: %d, col: %d\n", i, bd[i]);
}

bool putQueens(int bd[], int row){
  if (row == n) return true;
  //print(bd);
  
  for(int i=0; i < n; ++i){
    bool safe = true;
    for(int j=0; j < row; ++j)//aqui!!
      if(bd[j] == i || j + bd[j] == row + i || j - bd[j] == row - i){
	safe = false;
	break;
      }

    if(safe){
      bd[row] = i;
      if(putQueens(bd, row + 1))
	return true;
    }
  }
  
  //printf("btking...\n");
  return false;
}

int main(){
  scanf("%d", &n);
  int bd[n] = {};//Hace cosas raras ._______. corrijo: si y solo si el codigo esta malo .__.
  // for(int i=0; i< n; ++i)
  //   printf("%d\n", bd[i]);
  
  if(putQueens(bd, 0))
    print(bd);
  else
    printf("No, ma fren, este no tiene solucion :v");
  
  return 0;
}
