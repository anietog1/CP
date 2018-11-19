#include <vector>

using namespace std;

class UnionFind{
private:
  vector<int> p, rank, sizes;

public:
  UnionFind(int n){
    rank.assign(n, 0);
    p.assign(n,0);
    sizes.assign(n,1);
    
    for(int i=0; i<n; ++i)
      p[i] = i;
  }

  int findSet(int i){
    return (p[i] == i)? i : findSet(p[i]);
  }

  bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
  }

  void unionSet(int i, int j){
    if(!isSameSet(i, j)){
      int x = findSet(i), y = findSet(j);

      if(rank[x] > rank[y]){
	p[y] = x;
	sizes[x] += sizes[y];
      }else{
	p[x] = y;
	sizes[y] += sizes[x];
	if(rank[x] == rank[y])
	  rank[y]++;
      }
    }
  }

  int numDisjointSets(){
    int count = 0;
    
    for(int i=0; i<p.size(); ++i)
      if(p[i] == i) ++count;
    
    return count;
  }

  int sizeOfSet(int i){
    return sizes[findSet(i)];
  }
};
