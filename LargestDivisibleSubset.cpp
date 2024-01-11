class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++) hash[i]=i;

        int maxlenid=0;
        int maxlen=0;
        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                        if(maxlen<dp[i]){
                            maxlen=dp[i];
                            maxlenid=i;
                        }
                    }
                }
            }
        }

        vector<int>ans;
        int i=maxlenid;
        while(true){
            ans.push_back(nums[i]);
            i=hash[maxlenid];
            if(maxlenid==i) break;
            maxlenid=i;
        }

        return ans;
        
    }
};
