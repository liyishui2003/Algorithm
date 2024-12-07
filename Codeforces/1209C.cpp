#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
  int id,val;
  bool operator < (const node a) const{
	   if(val==a.val) return id>a.id;
	   return val<a.val;
  }
};
void solve(){
    int n,k;
    cin>>n>>k;
    priority_queue<node,vector<node>,less<node>>q;
    for(int i=1;i<=n;i++) {
      int x;
      cin>>x;
      x%=k;
      q.push((node){i,x});
    }

    
    while (!q.empty())
    {
       node v=q.top();
       q.pop();
       cout<<v.id<<" "<<v.val<<endl;
    }
    cout<<endl;
}
int main(){
    


    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}