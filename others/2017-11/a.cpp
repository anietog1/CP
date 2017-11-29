#include <iostream>

using namespace std;
int n = 12;
string escala[] = {"DO", "DO#",
		   "RE", "RE#",
		   "MI",
		   "FA", "FA#",
		   "SOL", "SOL#",
		   "LA", "LA#",
		   "SI"};

int main(){
  int corrida;
  string s;
  int pos;
  cin >> corrida >> s;
  corrida %= n;
  
  for(int i=0;i<n;++i)
    if(escala[i] == s)
      pos = i;

  pos -= corrida;
  
  if(pos < 0)
    pos = n + pos;
  
  cout << escala[pos] << endl;
}
