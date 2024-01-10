class Solution {
    int f(int ind1,int ind2,string &text1,string &text2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

        if(text1[ind1]==text2[ind2]) return dp[ind1][ind2]=1+f(ind1-1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2]=max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
    }
    int lcs(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,text1,text2,dp);
    }

    int answer(auto&s1,auto&s2){
        string rev1=s1;
        reverse(rev1.begin(),rev1.end());
        string rev2=s2;
        reverse(rev2.begin(),rev2.end());

        return lcs(s1,rev1)*lcs(s2,rev2);
    }
public:
    int maxProduct(string s) {
        int n=s.length();
        int maxi=0;
        for(int mask=0;mask<=(1<<n)-1;mask++){
            string s1="",s2="";
            for(int i=n-1;i>=0;i--){
                if(mask&(1<<i)){
                    s1+=s[i];
                }else{
                    s2+=s[i];
                }
            }

            maxi=max(maxi,answer(s1,s2));
        }
        return maxi;
    }
};
