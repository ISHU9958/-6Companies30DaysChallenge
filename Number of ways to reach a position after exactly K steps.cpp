#define mod (int)(1e9+7)
class Solution {

    int f(int s,int e,int k,vector<vector<int>>&dp){

        if(k==0){
            return s==e;
        }
        if(dp[s+1000][k]!=-1) return dp[s+1000][k] % mod;
        int left=f(s+1,e,k-1,dp)%mod;
        int right=f(s-1,e,k-1,dp)%mod;
        return dp[s+1000][k]= (left+right)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3001,vector<int>(k+1,-1));
        return f(startPos,endPos,k,dp);
    }
};
