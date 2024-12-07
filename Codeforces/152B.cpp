#include<bits/stdc++.h>
using namespace std;
int jump(int at,int to,vector<int> nums){
        int ans=to;
        for(int i=at;i<=min(to,(int)nums.size()-1);i++){
            ans=max(ans,i+nums[i]);
        }
        return ans;
    }
    bool canJump(vector<int>& nums){
        int at=0,to=nums[0];
        while(at<nums.size()-1){
            int newAt=jump(at,to,nums);
            if(newAt==to) break;
            at=to+1,to=newAt;
           // cout<<at<<" "<<to<<endl;
        }
        return at>=nums.size()-1 ? true : false;
    }
int main(){
    vector<int>nums;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        nums.push_back(x);
    }
    cout<<canJump(nums);
}