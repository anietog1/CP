#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
  string last, name;

  student(){}
  
  student(string name, string last)
    :name(name),last(last){}

  bool operator<(student &b){
    int c = last.compare(b.last);
    if(c < 0)
      return true;
    if(c > 0)
      return false;

    c = name.compare(b.name);
    if(c < 0)
      return true;
    if(c > 0)
      return false;

    return false;
  }

  void print(){
    cout << name << " " << last << endl;
  }
};

int main(){
  int n;
  string name, last;
  vector<student> students;
  
  cin >> n;
  while(n){
    cin >> name >> last;
    student a(name, last);
    students.push_back(a);
    --n;
  }

  sort(students.begin(), students.end());
  for(int i=0; i < students.size(); ++i)
    students[i].print();

  return 0;
}
