class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int,int>lost,win;
        for(auto &it:matches){
            lost[it[1]]++;
            win[it[0]]++;
        }

        vector<int>winners,lossers;
        for(auto&it:win){
            if(!lost.count(it.first)){
                winners.push_back(it.first);
            }
        }

        for(auto&it:lost){
            if(it.second==1){
                lossers.push_back(it.first);
            }
        }

        return {winners,lossers};

    }
};
