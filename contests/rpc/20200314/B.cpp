#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<pair<int,int>> a;
	for(int i = 0 ; i < 30 ; ++i){
		a.push_back(make_pair(0,-1));
	}
	
//	memset(a,0,a+s.size());
	for(int i = 0 ; i < s.size() ; ++i){
	//	cout<<-(s[i]-'a')<<'\n';
		a[s[i]-'a'] = make_pair(a[s[i]-'a'].first+1,-(s[i]-'a'));
	//	cout<<a[s[i]-'a'].first<<" "<<a[s[i]-'a'].second<<'\n';
	}
	sort(a.begin(), a.end(), greater<pair<int,int>>());
	for(int i = 0 ; i < a.size() ; ++i){
		for(int j = 0 ; j < a[i].first ; ++j){
			cout<<char(-a[i].second+'a');
		}
	}
}