#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	int len=s.length();
	int cnt2=0;
	for(int i=1;i<len;i+=2){
		if(s[i]=='1') s[i]='0';
		else if(s[i]=='0') s[i]='1';
	}
	int cnt1=0,cnt0=0;
	for(int i=0;i<len;i++){
		cnt1+=(s[i]=='1');
		cnt0+=(s[i]=='0');
		cnt2+=(s[i]=='2');
	}
//	cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<"\n";
	while(cnt2){
		if(cnt1>cnt0){
			cnt0++;
		}
		else if(cnt1==cnt0){
			cnt0++;	
		}
		else if(cnt1<cnt0){
			cnt1++;
		}
		cnt2--;
	}
	cout<<abs(cnt1-cnt0)<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
