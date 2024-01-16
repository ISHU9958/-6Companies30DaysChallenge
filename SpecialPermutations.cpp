#define mod (int)(1e9+7)
class Solution {
    int f(int prevbit,int mask,auto&nums,auto &dp){

        if(mask==(1<<nums.size())-1) return 1;
        if(dp[prevbit+1][mask]!=-1) return dp[prevbit+1][mask];
        int total=0;
        for(int i=0;i<nums.size();i++){
            if(prevbit==-1 || (!(mask&(1<<i)) && (nums[i]%nums[prevbit]==0 || nums[prevbit]%nums[i]==0) )){
                total=(total%mod+f(i,mask|(1<<i),nums,dp)%mod)%mod;
            }
        }

        return dp[prevbit+1][mask]= total%mod;
    }
public:
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(1<<n,-1));
        return f(-1,0,nums,dp);
    }
};
