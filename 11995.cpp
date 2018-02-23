#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    queue<int> q;
    stack<int> s;
    priority_queue<int> pq;
    bool isq, iss, ispq = isq = iss = true;
    while(n--){
      int c, x;
      cin >> c >> x;
      if(c == 1)
	q.push(x), s.push(x), pq.push(x);
      else {
	if(!q.size() || q.front() != x)
	  isq = false;
	if(!s.size() || s.top() != x)
	  iss = false;
	if(!pq.size() || pq.top() != x)
	  ispq = false;

	if(q.size())
	  q.pop();
	if(s.size())
	  s.pop();
	if(pq.size())
	  pq.pop();
      }
    }

    if(isq && !iss && !ispq)
      cout << "queue" << endl;
    else if(!isq && iss && !ispq)
      cout << "stack" << endl;
    else if(!isq && !iss && ispq)
      cout << "priority queue" << endl;
    else if(isq || iss || ispq)
      cout << "not sure" << endl;
    else
      cout << "impossible" << endl;
  }
}
