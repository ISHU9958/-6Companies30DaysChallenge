#define ll long long
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        int n=aliceValues.size();
        priority_queue<pair<ll,pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            ll total=aliceValues[i]+bobValues[i];
            pq.push({total,{aliceValues[i],bobValues[i]}});
        }

        ll alice=0,bob=0;
        ll alternate=0;

        while(!pq.empty()){
            if(alternate%2==0){
                // alice will pick
                alice+=pq.top().second.first;
            }
            else{
                bob+=pq.top().second.second;
            }
            pq.pop();
            alternate++;
        }

        return alice>bob ? 1 : (alice<bob ? -1 : 0);
    }
};
