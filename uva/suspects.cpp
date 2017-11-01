//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=636&page=show_problem&problem=3638
#include <iostream>

using namespace std;
#define MAXN 30010

int g[MAXN];
int sizes[MAXN];

void clean(int n){
  for(int i=0; i < n; ++i){
    g[i] = i;
    sizes[i] = 1;
  }
}

int find(int i){
  return g[i] == i? i : g[i] = find(g[i]);
}

void link(int i, int j){
  int x = find(i), y = find(j);
  if(x != y){
    if(x < y){
      g[y] = x;
      sizes[x] += sizes[y];
    }else{
      g[x] = y;
      sizes[y] += sizes[x];
    }
  }
}

// void print(int n, int arr[]){
//   for(int i=0; i < n; ++i){
//     cout << arr[i] << " ";
//   }

//   cout << endl;
// }

int main(){
  int n, m, k;

  while(cin >> n >> m){
    if(!(n|m))
      break;
    
    clean(n);
    
    while(m--){
      cin >> k;

      if(k){
	int parent;
	cin >> parent;
	for(int i = 1; i < k; ++i){
	  int curr;
	  cin >> curr;
	  link(parent, curr);
	  //print(n, g);
	  //print(n, sizes);
	}
      }
    }

    cout << sizes[0] << endl;
  }

  return 0;
}
