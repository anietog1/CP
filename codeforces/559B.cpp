#include <iostream>
#include <vector>

using namespace std;

string a, b;
vector<int> a1, a2, b1, b2;

void pass(string const& str, bool left, vector<int>& vect){
  vect.reserve('z' - 'a');
  
  if(left)
    for(int i=0;i<str.size()/2;++i)
      ++vect[str[i] - 'a'];
  else
    for(int i=str.size()/2;i<str.size();++i)
      ++vect[str[i] - 'a'];
}

int main(){
  cin >> a >> b;
  if(a == b){
    cout << "YES" << endl;
  }else if(a.size() & 1){//if odd, not two equal halves
    cout << "NO" << endl;
  }else{
    pass(a, false, a1);
    pass(a, true, a2);
    pass(b, false, b1);
    pass(b, true, b2);

    if((a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
