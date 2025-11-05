#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,f,vis[100005];
struct seg{
	int l,r;
	int id;
}a[100005];
bool cmp(seg a,seg b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.r<b.r;
}
bool cmp2(seg a,seg b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.r>b.r;
}
void solve(){
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		a[i].id=i;
		vis[i]=0;
	}
	sort(a+1,a+n+1,cmp);
	//判断f是否落在某个线段之间
	int flag=0;
	for(int i=1;i<=n;i++){
		if(a[i].l<=f&&f<=a[i].r){
			flag=1;break;
		}
	}
	ll ans=0;
	if(flag==0){
		for(int i=1;i<=n;i++){
			if(a[i].l>f){
				//找到的第一个l就是最近的
				ans+=a[i].l-f;
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		ans+=a[i].r-a[i].l;
	}
	int maxr=a[1].r;
	for(int i=1;i<=n;i++){
		if(maxr<a[i].l && maxr>=f){
			ans+=a[i].l-maxr;
		}
		maxr=max(maxr,a[i].r);
	}
	
	cout<<ans<<"\n";
	
	sort(a+1,a+1+n,cmp2);
	if(flag==0){
		//f不在某线段中
		int pos=-1;
		for(int i=1;i<=n;i++){
			if(a[i].l>f){
				pos=i;
				break;
			}
		}
		if(pos!=-1){
			//找到了
			int maxr=a[pos].r;
			cout<<a[pos].id<<" ";
			vis[pos]=1;
			for(int i=pos+1;i<=n;i++){
				if(a[i].r>=maxr){
					vis[i]=1;
					cout<<a[i].id<<" ";
					maxr=a[i].r;
				}
			}
			for(int i=n;i>=1;i--){
				if(vis[i]==0){
					cout<<a[i].id<<" ";
				}
			}
			cout<<"\n";
		}
		else {
			//没找到
			for(int i=n;i>=1;i--){
				cout<<a[i].id<<" ";
			}
			cout<<"\n";
		}
	}
	else {
		int pos=-1;
		for(int i=1;i<=n;i++){
			if(a[i].l<=f && f<=a[i].r){
				pos=i;
				break;
			}
		}
		int maxr=a[pos].r;
		cout<<a[pos].id<<" ";
		vis[pos]=1;
		for(int i=pos+1;i<=n;i++){
			if(a[i].r>=maxr){
				vis[i]=1;
				cout<<a[i].id<<" ";
				maxr=a[i].r;
			}
		}
		for(int i=n;i>=1;i--){
			if(vis[i]==0){
				cout<<a[i].id<<" ";
			}
		}
		cout<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}

/*
8
12 30
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 23
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 18
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 12
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 6
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 26
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 22
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27
12 1000000000
1 3
2 5
6 7
4 10
6 8
12 15
14 16
20 21
19 22
25 26
26 28
26 27



7
12 18
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
12 13
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
12 12
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
12 6
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
12 9
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
12 22
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
12 2
1 2
4 5
7 8
9 10
3 11
7 15
7 18
12 13
16 17
19 20
14 21
23 25
*/
