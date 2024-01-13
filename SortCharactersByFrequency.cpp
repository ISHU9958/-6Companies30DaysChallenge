class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &it:s){
            mp[it]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto &it:mp){
            char ch=it.first;
            int freq=it.second;

            pq.push({freq,ch});
        }

        string ans="";
        while(!pq.empty()){
            auto &pr=pq.top();

            int freq=pr.first;
            char ch=pr.second;

            while(freq--){
                ans+=ch;
            }

            pq.pop();
        }

        return ans;
    }
};
