

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        set<pair<int,string>>st;
        for(auto &it:words){
            mp[it]++;
        }

        for(auto &it:mp){
            st.insert({-(it.second),it.first});
        }

        vector<string>ans;
        
        for(int i=1;i<=k;i++){
            auto it=st.begin();
            auto pr=*it;
            ans.push_back(pr.second);
            st.erase(pr);
        }
        return ans;
    }
};
