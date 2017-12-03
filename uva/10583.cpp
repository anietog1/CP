//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=1524

#include <iostream>

using namespace std;
#define MAXN 50010

int rels[MAXN];

void init(int n){
  for(int i=0; i <= n; ++i)
    rels[i] = i;
}

int findRel(int i){
  return (rels[i] == i)? i: rels[i] = findRel(rels[i]);
}

bool merge(int i, int j){
  int x = findRel(i), y = findRel(j);

  if(x != y){
    rels[x] = y;
    return true;
  }

  return false;
}

int main(){
  int n, m;
  int turn = 1;
  cin >> n >> m;
  while(n != 0 && m != 0){
    init(n);

    int i, j;
    while(m--){
      cin >> i >> j;
      if(merge(i, j)){
	--n;
      }
    }
    cout << "Case " << turn << ": " << n << endl;
    
    ++turn;
    cin >> n >> m;
  }

  return 0;
}
