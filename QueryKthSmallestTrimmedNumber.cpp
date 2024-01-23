#define ll long long
class Solution {

    int findKthSmallest(auto prior,int k){
        vector<pair<string,int>>temp;
        for(int i=1;i<=k-1;i++){
            temp.push_back(prior.top());
            prior.pop();
        }

        int index=prior.top().second;
        for(auto it:temp){
            prior.push(it);
        }
        return index;
    }
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int m=nums.size(),n=nums[0].size();

        // i use the precomputation technique, i first store all the possible trim values 
        unordered_map<int,priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>>>mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string temp=nums[i].substr(j);
                // long long x=stoll(temp);
                mp[n-j].push({temp,i});
            }
        }

        // i have already stored the lenth in map and corresponding elements 
        vector<int>ans;
        for(auto it:queries){
            int k=it[0];
            int trim=it[1];
            auto prior=mp[trim];
            int index=findKthSmallest(prior,k); // i find out the kth smallest element index
            ans.push_back(index);
        }
        return ans;
    }
};
