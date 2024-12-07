#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 7;

int n, m, t;
int x, y;

int main()
{
    cout<<(2%3)<<endl;
    cout<<(4%7)<<endl;
	scanf("%d", &t);
	while(t -- ) {
		scanf("%d%d", &x, &y);
		int a = 1, b = 1;
		ll ans = 0;
		for(; b * b  - 1 <= x && b <= y; ++ b) 
			ans += b-1;	   

		int l = b + 1, r;  
		for(; l <= x && l <= y + 1; l = r + 1) {
			r = min(x / (x / l), y + 1);
			ans += x / l * (r - l + 1); 
			if(r == y + 1) break;
		} 
		cout << ans << endl;
	}		
	return 0;
}
 