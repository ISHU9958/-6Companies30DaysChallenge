class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int>mp;
        int n=s.length();
        int bulls=0,cows=0;
        for(int i=0;i<n;i++){
            if(s[i]==g[i]) bulls++;
            else mp[g[i]]++;
        }

        for(int i=0;i<n;i++){
            if(!mp.count(s[i])) continue;
            if(s[i]!=g[i]){
                cows++;
                if(mp[s[i]]>1)
                    mp[s[i]]--;
                else mp.erase(s[i]);
            }
        }

        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};
