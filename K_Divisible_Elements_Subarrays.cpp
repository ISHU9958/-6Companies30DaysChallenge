class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        unordered_set<string>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string temp;
            int ct=0;
            for(int j=i;j<n;j++){

                temp.push_back(nums[j]);
                if(nums[j]%p==0) ct++;
                if(ct>k) break;
                if(ct<=k) st.insert(temp);


            }
        }
        return st.size();
    }
};
