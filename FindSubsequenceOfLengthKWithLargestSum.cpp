class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>contain;
        for(int i=0;i<n;i++){
            contain.push_back({nums[i],i});
        }
        sort(contain.begin(),contain.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=n-k;i<n;i++){
            int val=contain[i][0];
            int idx=contain[i][1];

            pq.push({idx,val});
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
