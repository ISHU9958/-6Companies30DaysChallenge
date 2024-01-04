class Solution {
public:
    int mod=1e9+7;
    long long count(int index,int &delay,int &forget,int &n, vector<int>&dp){
        
       if(dp[index]!=-1)return dp[index];

       long long cnt=0;
       cnt++;
  
       if(index+forget<=n)cnt--;

       for(int i=index+delay;i<index+forget && i<=n;i++){
           cnt=cnt+count(i,delay,forget,n,dp);
           cnt=cnt%mod;
       }
       return dp[index]=cnt;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
       vector<int>dp(1001,-1);
       return count(1,delay,forget,n,dp); 
    }
};
