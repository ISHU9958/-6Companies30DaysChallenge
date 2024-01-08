class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        int n=s.length();
        vector<string>ans;
        for(int i=9;i<n;i++){
            mp[s.substr(i-9,10)]++;
            if(mp[s.substr(i-9,10)]>1){
                ans.push_back(s.substr(i-9,10));
                mp[s.substr(i-9,10)]=-1e8;
            }
        }
        return ans;
    }
};
