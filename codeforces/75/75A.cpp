#include <iostream>

using namespace std;

#define d(x) cout << #x << " = " << x << endl

int a, b, c;

int remove(int x){
  int leftD = x/10;
  int rightD = x%10;

  if(leftD == 0)
    return rightD;
  
  if(rightD == 0)
    return remove(leftD);

  return remove(leftD)*10 + rightD;
}

void remove(){
  a = remove(a);
  b = remove(b);
  c = remove(c);
}


int main(){
  cin >> a >> b;
  c = a + b;
  
  remove();
  
  bool correct = (a + b) == c;
  if(correct)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
