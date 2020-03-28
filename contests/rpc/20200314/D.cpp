#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,pp,c,k;
	cin>>n>>pp;
	int p[pp];
//	memset(p,-1,pp*sizeof(int));
	for(int i = 0 ; i < pp ; ++i){
		p[i] = -1;
	}
	unordered_map<string, int> m;
	int a[n];
	string s;
	for(int i = 0 ; i < n-1 ; ++i){
		cin>>s;
		if(m.find(s) == m.end()) m[s] = i;
		a[i] = m[s];
	}
	cin>>c;
	deque<pair<int, int>> dq;
	for(int i = 0 ; i < c ; ++i){
		cin>>k>>s;
		dq.push_back(make_pair(k,m[s]));
	}
	int answer = 1;
	while(answer){
		for(int i = 0 ; i < pp ; ++i){
			pair<int, int> temp = dq.front();
			dq.push_back(temp);
			dq.pop_front();
			int count = 0;
			bool find  = false;
			if(temp.first != 3){
				for(int j  = p[i] +1 ; j < n -1 ; ++j){
					if(a[j] == temp.second){
						count++;
						if(count == temp.first){
							p[i] = j;
						find  = true;
							break;
						}
					}
				}
				if(!find){
					cout<<i+1;
					answer = 0;
					break;
				}
			}
			else{for(int j = 0 ; j < n-1 ; ++j){
				if(a[j] == temp.second){ p[i] = j;break;}}
			}
		}
	}
}
