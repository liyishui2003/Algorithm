#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int num[n+5];
    for(int i=1;i<=n;i++){

        for(int j=1;j<=i;j++) num[j]=j;
        cout<<i<<" #"<<endl;
        do  {  
            int flag=1;
            for(int l=1;l<=i;l++){
                for(int r=l;r<=i;r++){
                    int sum=0;
                    
                    for(int k=l;k<=r;k++) sum+=num[k];
                    
                    if(sum%(r-l+1)) flag=0;
                }
            }

            if(flag) {
                for(int k=1;k<=i;k++) cout<<num[k]<<" ";
                cout<<endl; 
            }
        }while(next_permutation(num+1,num+i+1));  
    }
}