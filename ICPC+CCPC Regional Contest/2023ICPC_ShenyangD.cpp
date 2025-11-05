#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 5005;
ull ha[N],hb[N],p[N];
const ull mod = 31;
string a,b;
int lena,lenb;
unordered_map<ull,int>mpa,mpb;

constexpr int SZ = 1000000;
constexpr int M = 999997;
struct hash_map {  // 哈希表模板
	
	struct data {
		long long u;
		int v, nex;
	};  // 前向星结构
	
	data e[SZ << 1];  // SZ 是 const int 表示大小
	int h[SZ], cnt;
	
	int hash(long long u) { return (u % SZ + SZ) % SZ; }
	
	// 这里使用 (u % SZ + SZ) % SZ 而非 u % SZ 的原因是
	// C++ 中的 % 运算无法将负数转为正数
	
	int& operator[](long long u) {
		int hu = hash(u);  // 获取头指针
		for (int i = h[hu]; i; i = e[i].nex)
			if (e[i].u == u) return e[i].v;
		return e[++cnt] = data{u, -1, h[hu]}, h[hu] = cnt, e[cnt].v;
	}
	
	hash_map() {
		cnt = 0;
		memset(h, 0, sizeof(h));
	}
};




ull geta(int l,int r){
	return ha[r]-ha[l-1]*p[r-l+1];
}
ull getb(int l,int r){
	return hb[r]-hb[l-1]*p[r-l+1];
}
int lcs[N][N];
struct node{
	int sz;
	int sum[N];
	int q(int l,int r){
		if(l>r) return 0;
		if(l==0) return sum[r];
		return sum[r]-sum[l-1];
	}
}t[N];
long long f(string a,string b,int op){
	// master:a
	int len=a.length()-1;
	memset(lcs,0,sizeof lcs);
	// i:the first j:the second
	for(int i=len;i>=1;i--)
		for(int j=len;j>=i;j--){
			if(a[i]==a[j]) lcs[i][j]=lcs[i+1][j+1]+1;
			else lcs[i][j]=0;
	}
	for(int i=1;i<=len;i++){
		t[i].sz=0;
		t[i].sum[0]=0;
		for(int j=i;j>=1;j--){
			t[i].sz++;
			int sz=t[i].sz;
			t[i].sum[sz]=t[i].sum[sz-1]+(op==1?mpb[geta(j,i)]:mpa[getb(j,i)]);
		//	cout<<"[i,j] "<<j<<","<<i<<" "<<(op==1?mpb[geta(j,i)]:mpa[getb(j,i)])<<'\n';
		}
	}
	int pos;
	long long ret=0;
	for(int i=1;i<=len;i++){
		for(int j=i+1;j<=len;j++){
			int l=lcs[i][j];
		//	cout<<i<<" "<<j<<" "<<l<<'\n';
			if(!l) continue;
			pos=min(i+l-1,j-1);
			ret+=t[j-1].q(j-(pos+1),j-(i+1));
		/*	
			cout<<"["<<i<<","<<j<<"] sz="<<t[j-1].sz<<'\n';
			cout<<"lcs= "<<l<<'\n';
			cout<<j-pos-1<<" "<<j-i-1<<'\n';
			cout<<"q= "<<t[j-1].q(j-(pos+1),j-(i+1))<<'\n';
		*/
		}
	}
	return ret;
}
void solve(){
	cin>>a>>b;
	
	lena=a.length(),lenb=b.length();
	a=" "+a,b=" "+b;
	
	p[0]=1;
	for(int i=1;i<=max(lena,lenb);i++)
		p[i]=p[i-1]*mod;
	for(int i=1;i<=lena;i++){
		ha[i]=ha[i-1]*mod+a[i];
	}
	for(int i=1;i<=lenb;i++){
		hb[i]=hb[i-1]*mod+b[i];
	}

	for(int i=1;i<=lena;i++)
		for(int j=i;j<=lena;j++)
			mpa[geta(i,j)]++;
	
	for(int i=1;i<=lenb;i++)
		for(int j=i;j<=lenb;j++)
			mpb[getb(i,j)]++;
	
	long long ans=0,tot=0;
	ans+=f(a,b,1);
	ans+=f(b,a,0);
	for(int i=1;i<=lena;i++){
		for(int j=i;j<=lena;j++)
			tot+=mpb[geta(i,j)];
	}
	ans+=tot;
	cout<<ans<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
}
