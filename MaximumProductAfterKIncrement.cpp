#define mod (int)(1e9+7)
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto &it:nums){
            pq.push(it);  // nlogn
        }

        for(int i=1;i<=k;i++){
            int top=pq.top();
            pq.pop();
            pq.push(top+1);
        }

        long long ans=1;

        while(!pq.empty()){
            ans=((ans % mod) * (pq.top() % mod)) %mod;
            pq.pop();
        }
        return ans;
    }
};
