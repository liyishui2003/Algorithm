#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=1e6+5;
int power(int a, int b, int p=mod)
{
	if(b==0)
		return 1;
	if(a==0)
		return 0;
	int res=1;
	a%=p;
	while(b>0)
	{
		if(b&1)
			res=(1ll*res*a)%p;
		b>>=1;
		a=(1ll*a*a)%p;
	}
	return res;
}
int fact[N],inv[N];
void pre()
{
	fact[0]=1;
	inv[0]=1;
	for(int i=1;i<N;i++)
		fact[i]=(i*fact[i-1])%mod;
	for(int i=1;i<N;i++)
		inv[i]=power(fact[i], mod-2, mod);
}
int nCr(int n, int r, int p=mod) 
{ 
	if(r>n || r<0)
		return 0;
	if(n==r)
		return 1;
	if (r==0) 
		return 1; 
	return (((fact[n]*inv[r]) % p )*inv[n-r])%p;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int sum=0,mm=m;
    while(mm--){
        int a,b,f;cin>>a>>b>>f;
        sum=(sum+f)%mod;
    }

    int base=nCr(n,2);
    base=power(base,mod-2)*sum%mod*k%mod;
 
    int div=0;
    int chose=power((n*(n-1)/2ll)%mod,mod-2)%mod;

    for(int i=1;i<=k;i++){
         int sum=(i*(i-1)/2)%mod;
         int prob=nCr(k,i)*power(chose,i)%mod;
         int un_prob=((n*(n-1)/2ll)%mod-1+mod)%mod*chose%mod;
         un_prob=power(un_prob,k-i);

         prob=prob*un_prob%mod;

         sum=sum*prob%mod;
         div=(div+sum)%mod;
    }
    
    div=div*m%mod;
    cout<<(base+div)%mod<<endl;

}
signed main( ){
    
    pre();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}