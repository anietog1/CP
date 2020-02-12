void getZ(string const& str, int Z[]) { // recordar str = pat$str
  int n = str.length();
  int L, R, k;
  L = R = 0; // [L,R] es una ventana que hace match con un prefijo de str
  for(int i = 1; i < n; ++i) {
    if(i > R) { // nada hace match, calcular prefijo
      L = R = i;
      while(R < n && str[R - L] == str[R]) R++;
      Z[i] = R - L;
      R--;
    } else {
      k = i - L; // con qué debo comparar, k indica la posición
      if(Z[k] < R - i + 1) Z[i] = Z[k]; // uso lo que ya tenía
      else { // sino, desde R sigo calculando para continuar (hizo match, pero es más largo)
        L = i;
        while(R < n && str[R - L] == str[R]) R++;
        Z[i] = R-L;
        R--;
      }
    }
  }
}
