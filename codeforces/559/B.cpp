#include <iostream>
#include <vector>

using namespace std;
//Note equivalence is an equivalence relation: you can sort the strings   //By minimal comparable parts, that's it... How didn't I notice it? :c
//All being said, I read the tutorial :)
string a, b;

string sort(string s){
  if(s.size() & 1)
    return s;
  else {
    string s1 = sort(s.substr(0, s.size()/2)),
      s2 = sort(s.substr(s.size()/2));
    
    if(s1 < s2)
      return s1 + s2;
    else
      return s2 + s1;
  }
}

int main(){
  cin >> a >> b;
  a = sort(a);
  b = sort(b);
  if(a == b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
