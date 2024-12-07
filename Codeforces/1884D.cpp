#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> cnt(n + 1);
		for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
		
		vector<ll> g(n + 1);
		for (int i = n; i; i--) {
			ll s = 0;
			for (int j = i; j <= n; j += i)
				s += cnt[j];
			g[i] = s * (s - 1) / 2;
			for (int j = 2 * i; j <= n; j += i)
				g[i] -= g[j],cout<<i<<" - "<<j<<" "<<g[j]<<endl;
		}
		for(int i=1;i<=n;i++) {
			if(g[i]) cout<<i<<" # "<<g[i]<<endl;
		}
		cout<<"==="<<endl;
		for (int i = 1; i <= n; i++){
			if (cnt[i]){
				cout<<"at :"<<i<<endl;
				for (int j = i; j <= n; j += i){
					g[j] = 0,cout<<i<<" remove "<<j<<endl;
				}	
			}
		}
			
		
		ll ans = 0;
		for (int i = 1; i <= n; i++) ans += g[i];
		for(int i=1;i<=n;i++) {
			if(g[i]) cout<<i<<" # "<<g[i]<<endl;
		}
		cout<<666<<endl;
		cout << ans << "\n";
	}
	return 0;
}
