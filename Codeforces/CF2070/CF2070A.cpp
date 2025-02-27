#include<bits/stdc++.h>
using namespace std;
int ask(int x){
	int ans =max((x/15)*3,1);
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;cin>>t;
	while(t--){
		int x;
		cin>>x;
		if(x>15){
			int least  = (x/15)*15;
			int ans = ask(least);
			ans += min(2,abs(x-least));
			cout<<ans+1<<endl;	
		}
		else {
			
			int ans = 0;
			for(int i = 0;i <= x; i++){
				ans+=((i%3)==(i%5));
			}
			cout<<ans<<endl;
		}
	}
}
