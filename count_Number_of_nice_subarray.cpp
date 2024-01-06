class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int>nextodd;
        int n=nums.size();
        nextodd[n-1]=n;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]&1){  // if odd
                nextodd[i]=i+1;
            }else{
                nextodd[i]=nextodd[i+1];
            }
        }

        int i=0,j=0;
        int ans=0;
        int odd=0;
        while(j<n){
            if(nums[j]&1){  // if current value is odd
                odd++;
            }
            if(odd<k){
                j++;
            }
            else if(odd==k){

            
                while(i<n && j<n && odd==k){
                    int nextOddId=nextodd[j];
                    ans+=nextOddId-j;
                    if(nums[i]&1){
                        odd--;
                    }
                    i++;
                }
                j=nextodd[j];
            }
        }

        return ans;
    }
};
