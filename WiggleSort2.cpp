class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto it:nums) cout<<it<<" ";
        int n=nums.size();
        int mid;
        if(n%2==0) mid=n/2-1;
        else mid=n/2;

        int i=mid,j=n-1;
        vector<int>ans;
        while(mid<j){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i--;
            j--;
        }

        if(n%2) ans.push_back(nums[i]);

        nums=ans;
    }
};
