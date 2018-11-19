#include <vector>
#include <iostream>

using namespace std;

class SegmentTree{
private:
  vector<int> st, A;
  int n;

  int left(int p){
    return p<<1;//2*p
  }

  int right(int p){
    return p<<1 + 1;
  }

  void build(int p, int L, int R){
    if(L == R)
      st[p] = L;//Si los dos limites son iguales, toma el [indice!]
    else{
      build(left(p), L, (L+R)/2);
      build(right(p), (L+R)/2 + 1, R);
      
      int p1 = left(p), p2 = right(p);
      st[p] = (A[p1] < A[p2])? p1:p2;//Construye de las hojas hacia arriba
    }
  }

  int rmq(int p, int L, int R, int i, int j){
    if( i > R || j < L) return -1;//fuera de rango
    if(L >= i && R <= j) return st[p];//esta acotado -> subconjunto, [i,j] incluido en [L,R]

    int p1 = rmq(left(p), L, (L+R)/2, i, j);
    int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);
    
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return (A[p1] < A[p2])? p1:p2;
  }
  
  void updateFrom(int p){
    int p1, p2;
    while(p!=0){
      p1 = left(p);
      p2 = right(p);
      st[p] = (A[p1] < A[p2]) p1: p2;
      p = p >> 1;
    }
  }

  int findInST(int p, int L, int R, int idx){
    if(L>i || R<i) return -1;//ELIMINA OPCION DE UNA: SIGUE SOLO 1 CAMINO
    if(L == R) return p;
    int p1 = findInST(left(p), L, (L+R)/2, idx);
    int p2 = findInST(right(p), (L+R)/2 + 1, R, idx);
    return (p1 != -1)? p1: p2;
  }
public:
  SegmentTree(const vector<int> &_A){
    A = _A; n = (int) _A.size();
    st.assign(4*n, 0);
    build(1, 0, n-1);
  }

  int rmq(int i, int j){
    return rmq(1, 0, n-1, i, j);
  }
  
  void update(int idx, int val){
    A[idx] = val;
    int p = findInST(1, 0, n-1, idx);
    updateFrom(p, val);
  }
};
