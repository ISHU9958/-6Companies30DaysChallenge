class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>>mp;
        for(auto &it:access_times){
            int x=stoi(it[1]);
            mp[it[0]].push_back(x);
        }

        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }

        vector<string>ans;
        for(auto &it:mp){
            
            vector<int>&temp=it.second;
            for(int i=2;i<temp.size();i++){
                if(temp[i]-temp[i-2]<100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        return ans;
    }
};
