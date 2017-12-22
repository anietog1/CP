#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> idx;
int p[100000], size[100000];

void clear(int f){
  for(int i=0;i<f;++i){
    p[i] = i;
    size[i] = 1;
  }
}

int find(int i){
  return p[i] == i? i : p[i] = find(p[i]);
}

void makefriend(int i, int j){
  int x = find(i), y = find(j);

  if(x != y){
    size[x] += size[y];
    p[y] = x;
  }
}

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int f;
    cin >> f;

    clear(f);
    idx.clear();
    
    int num = 0;
    while(f--){
      string a, b;
      cin >> a >> b;
      
      if(!idx.count(a))
	idx[a] = num++;
      
      if(!idx.count(b))
	idx[b] = num++;
      
      makefriend(idx[a], idx[b]);
      
      cout << size[find(idx[a])] << endl;
    }
  }
}
