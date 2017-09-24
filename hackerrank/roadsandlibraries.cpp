//#include <iostream>

//HackerRank pone mucho problema con el scanf
//Ademas, mandaba segmentation fault y en el pc corre perfectamente.
//SEGURO DE MI ALGORITMO :), sadly no lo pude subir...
#include <cstdio>
#include <bitset>

using namespace std;

#define MAXN 100010
//#define DEBUG

bitset<MAXN> g[MAXN];
bitset<MAXN> state;
int n, cl, cr, cost;

void reset(){
  cost = 0;
  for(int i=1; i <= n; ++i){
    g[i].reset();
    state[i] = false;
  }
}

void dfs(int s){
  state[s] = true;
  for(int i=1; i<=n; ++i)
    if(g[s][i] && !state[i]){

#ifdef DEBUG
      printf("Camino de %d a %d con costo de %d\n", s, i, cr);
#endif

      dfs(i);
      cost += cr;
    }
}

void calc(){
  if(cl <= cr) cost = cl*n;
  else{
    for(int i=1; i<=n; ++i)
      if(!state[i]){
	
#ifdef DEBUG
	printf("Libreria en %d con costo de %d\n", i, cl);
#endif
	cost += cl;
	dfs(i);
      }
  }
}

int main(){
  int q, m, i, j;
  //cin >> q;
  scanf("%d", &q);
  while(q){
    //cin >> n >> m >> cl >> cr;
    scanf("%d %d %d %d", &n, &m, &cl, &cr);
    reset();
    
    while(m){
      //cin >> i >> j;
      scanf("%d %d", &i, &j);
      g[i][j] = g[j][i] = true;
      --m;
    }
    
    calc();
    //cout << cost << endl;
#ifdef DEBUG
    printf("Costo total : ");
#endif
    printf("%d\n", cost);
    --q;
  }

  return 0;
}
