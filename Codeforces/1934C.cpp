#include<bits/stdc++.h>
using namespace std;
void out(int x,int y){
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
}
void outFind(int x,int y){
    cout<<"! "<<x<<" "<<y<<endl;
    fflush(stdout);
}
void solve(){
    int n,m,d[6];
    cin>>n>>m;
    out(1,1);
    cin>>d[1];
    if(d[1]==0){
        outFind(1,1); 
        return;
    }
    else{
       int x=1,y=1+d[1];
       if(y>m){
            x+=y-m;
            y=m;
       }
       out(x,y);// x,y->右上角
       cin>>d[2];
       if(d[2]==0) {
            outFind(x,y);
            return;
       }
       d[2]/=2;
       out(x+d[2],y-d[2]);//以右上角为圆心画圆
       cin>>d[3];
       if(d[3]==0){
            outFind(x+d[2],y-d[2]);
            return;
       }
       else {
          int x=1+d[1],y=1;//左下角
          if(x>n){
            y+=(x-n);
            x=n;
          }
          out(x,y);
          cin>>d[4];
          d[4]/=2;
          outFind(x-d[4],y+d[4]);
       }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}