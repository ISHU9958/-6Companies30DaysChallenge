class Solution {

    int lb(auto &arr,int tar){
        int i=0,j=arr.size()-1,ans=-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(arr[mid]<tar){
                ans=mid;
                i=mid+1;
            }
            else j=mid-1;
        }
        return ans;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ct=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            int val=arr1[i];
            int left=lb(arr2,arr1[i]-d);
            int right=upper_bound(arr2.begin(),arr2.end(),arr1[i]+d)-arr2.begin();

            if(right<=left || right==left+1){
                ct++;
            }
        }

        return ct;
    }
};
