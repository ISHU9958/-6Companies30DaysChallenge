class Solution {
public:
    
    bool issorted(vector<int>nums,int k,int l){
        int n=nums.size();
        
        vector<int>temp;
        
        for(int i=0;i<=k;i++){
            temp.push_back(nums[i]);
        }
        for(int j=l;j<n;j++){
            temp.push_back(nums[j]);
        }
        int m=temp.size();
        
        for(int i=0;i<m-1;i++){
            if(temp[i]>=temp[i+1]) return false;
        }
        return true;
    }
    
    
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int n=nums.size();
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(issorted(nums,i-1,j+1)){

                    ct++;
                }
            }
        }
        
        return ct;
    }
};
