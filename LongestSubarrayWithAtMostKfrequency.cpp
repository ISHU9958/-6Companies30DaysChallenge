class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(),maxi=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[nums[j]]++;

            while(i<=j && mp[nums[j]]>k){
                if(mp[nums[i]]==1) mp.erase(nums[i]);
                else mp[nums[i]]--;
                i++;
            }
            

            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
