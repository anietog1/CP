#include <bits/stdc++.h>
using namespace std;
int main(){
	double n,d,suma,k;
	cin>>n>>d;
	double a[int(n)];
	for(int i  = 0 ; i < n ; ++i) {
		cin>>a[i];
		suma += a[i];
	}
	for(int i  = 0 ; i < n ; ++i) {
		cout<<d*(a[i]/suma)<<'\n'; 
	}
}
