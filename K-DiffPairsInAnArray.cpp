class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_set<int>st;
        set<pair<int,int>>uniq;
        for(auto &it:nums){
            if(st.count(it-k)){

                if(it<=it-k){
                    uniq.insert({it,it-k});
                }
                else{
                    uniq.insert({it-k,it});
                }
            }
            st.insert(it);
        }
        return uniq.size();
    }
};
