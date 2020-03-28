#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,c;
	cin>>n>>c;
	int a[2][n];
	for(int i=0;i<n;++i){
		scanf("%d:%d",&a[0][i],&a[1][i]);
	}

	
	int sum=0;
	for(int i=0;i<n;++i){
		sum=sum+a[0][i]*60+a[1][i];
	}
	sum=sum-(n-1)*c;
	int h,m,s;
	
		h=sum/3600;
	    sum=sum%3600;
		m=sum/60;
		sum=sum%60;
		s=sum;

	
	string hh,mm,ss;
	
	if(h==0){
		hh="00";
	}else if(h>0 && h<10){
		hh="0"+to_string(h);
	}else{
		hh=to_string(h);
	}
	
	if(m==0){
		mm="00";
	}else if(m>0 && m<10){
		mm="0"+to_string(m);
	}else{
		mm=to_string(m);
	}
	
	if(s==0){
		ss="00";
	}else if(s>0 && s<10){
		ss="0"+to_string(s);
	}else{
		ss=to_string(s);
	}
	
	cout<<hh+":"+mm+":"+ss<<endl;
	return 0;
}