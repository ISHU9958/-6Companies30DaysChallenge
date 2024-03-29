class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        this->k=k;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        while(pq.size()>k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }

        return pq.top();
    }
};
