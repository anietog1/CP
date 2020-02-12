int parent[MAXN], rank[MAXN], size[MAXN];

void init() {
  for(int i = 0; i < MAXN; ++i)
    make_set(i);
}

void make_set(int v) {
  parent[v] = v;
  rank[v] = 0;
  size[v] = 1;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets_by_rank(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if(a != b) {
    if(rank[a] < rank[b])
      swap(a, b);
    parent[b] = a;
    if(rank[a] == rank[b])
      rank[a]++;
  }
}

void union_sets_by_size(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if(a != b) {
    if(size[a] < size[b])
      swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
}
