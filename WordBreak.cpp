class Solution {

    bool f(int i,int n,string &s,unordered_map<string,int>&mp,vector<int>&dp){

        if(i>n) return true;
        if(dp[i]!=-1) return dp[i];

        string temp;
        for(int j=i;j<=n;j++){
            temp=temp+s[j];
            if(mp.count(temp)){
                bool ans=f(j+1,n,s,mp,dp);
                if(ans) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }

        // f(i) represents fromt ith index to n-1 th index whether the given s can be segmented

        int n=s.length();
        vector<int>dp(n,-1);
        return f(0,n-1,s,mp,dp);
    }
};
