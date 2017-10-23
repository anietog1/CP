#include <cstdio>
#include <queue>

using namespace std;
#define MAXN 505

int grid[MAXN][MAXN];
int moves[MAXN][MAXN];
int m, n;

struct movement{
  int i, j, s;
  movement(int i, int j, int s)
    :i(i),j(j),s(s){}
};

void move(){
  queue<movement> q;
  q.push( movement(0,0,0) );

  while(!q.empty() && moves[m - 1][n - 1] == 0){
    movement curr = q.front();
    q.pop();

    int i = curr.i, j = curr.j, s = curr.s;
    if( i < 0 || j < 0 || i >= m || j >= n)
      continue;
    
    int k = grid[i][j];

    if(moves[i][j] == 0){
      //      printf(" %d, %d, %d\n", i, j, s);
      moves[i][j] = s++;
      
      if(k == 0)
	continue;
      
      q.push( movement(i + k, j, s) );
      q.push( movement(i, j + k, s) );
      q.push( movement(i - k, j, s) );
      q.push( movement(i, j - k, s) );
    }
  }
}

int main(){
  scanf("%d %d", &m, &n);
  char k;
  
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j){
      scanf(" %c", &k);
      grid[i][j] = (k - '0');
    }

  move();
  
  if( ((m == 1) && (n == 1)) || moves[m-1][n-1] != 0){
    printf("%d\n", moves[m-1][n-1]);
  }else{
    printf("IMPOSSIBLE\n");
  }
}
