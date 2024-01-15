class Solution {

    int low(auto&arr,double tar,int &n){
        int i=0;
        int j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(arr[mid]<=tar){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
public:
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        sort(ages.begin(),ages.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int x=ages[i];
            int lb=low(ages,0.5*x+7,n);
            int up=upper_bound(ages.begin(),ages.end(),x)-ages.begin();
            if(up==-1) up=n;

            if(lb<i && i<up) ans+=up-lb-2;

            else if((lb==i && i<up) || (lb<i && i==up)){
                ans+=up-lb-1;
            }
        }
        return ans;
    }
};
