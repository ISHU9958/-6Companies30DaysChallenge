class Solution {
    vector<int>dp;
    int n;
    int f(int i,auto &st,auto &s){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;

        for(int j=1;j<=s.length()-i;j++){
            string temp=s.substr(i,j);
            if(st.count(temp)){
                mini=min(mini,f(i+j,st,s));
            }
        }

        mini=min(mini,1+f(i+1,st,s));
        return dp[i]=mini;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>st;
        for(auto &it:dictionary){
            st.insert(it);
        }
        n=s.length();
        dp.resize(n,-1);
        return f(0,st,s);
    }
};
