#include <cstdio>

using namespace std;
#define MAXN 505
#define INF 1 << 30

int grid[MAXN][MAXN];
int moves[MAXN][MAXN];
int m, n;

void move(int i, int j, int s){
  if(i < 0 || j < 0 || i >= m || j >= n)
    return;
  
  if(s < moves[i][j]){
    moves[i][j] = ++s;//En los moves, suma de una a los steps
    int k = grid[i][j];

    if(k != 0){
      move(i + k, j, s);
      move(i, j + k, s);
      move(i - k, j, s);
      move(i, j - k, s);
    }
  }
}

void init(int m, int n){
  for(int i=0; i < m; ++i)
    for(int j=0; j < n; ++j)
      moves[i][j] = INF;
}

int main(){
  scanf("%d %d", &m, &n);
  char k;

  init(m, n);
  
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j){
      scanf(" %c", &k);
      grid[i][j] = (k - '0');
    }

  move(0,0,0);
  
  if(moves[m-1][n-1] < INF){
    printf("%d\n", moves[m-1][n-1] - 1);
  }else{
    printf("IMPOSSIBLE\n");
  }
}
