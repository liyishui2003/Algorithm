#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
const int N =1e6;
int a[N],d,ans[N];
char b[N];
ll sum;
stack<int>c;
int n, t,m;

void solve()
{
    int kai = 0;
    cin >> n>>m;
    
    int tmpl=-1,tmpr=n;

    for (int i = 0; i < n; i++){
        cin >> a[i]; 
    }

    for (int i = 0; i < n ; i++)
    {
        cin >> b[i];
        if (b[i] == 'L')
            kai++;
    }

    cout<<"kai: "<<kai<<endl;

    int l = kai;
    int r = kai;
    d = a[kai];
    c.push( a[kai] % m);
  //  cout<<kai<<" "<<d<<endl;
    for (int i = n-2; i >=0; i--)
    {

        if (b[i] == 'L') {
            d = (d % m * a[--l] % m) % m;
            c.push(d);
        }
            
        else if (b[i] == 'R') {
            d = (d % m * a[++r] % m) % m;
            c.push(d);
        }
        
    }
    
    for (int i = 0; i < n; i++) {
        int x = c.top();
        cout<<x<<" ";
        c.pop();
    }
}

int main(){
    cin >>t;
    while (t--){
        solve();
        cout << "\n";
    }

    return 0;
}