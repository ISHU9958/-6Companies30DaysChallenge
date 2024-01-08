#define ll long long
class Solution {
    vector<int>v;
    vector<vector<int>>rect;
    int n;
public:
    Solution(vector<vector<int>>& rects) {
        n=rects.size();
        ll area=0;
        for(auto &it:rects){
            ll a=it[0],b=it[1],x=it[2],y=it[3];
            area+=(x-a+1)*(y-b+1);
            v.push_back(area);
            rect.push_back(it);
        }
    }
    
    vector<int> pick() {
        ll totalpoints=rand()%v.back();
        int randRecIndx=upper_bound(v.begin(),v.end(),totalpoints)-v.begin();
        vector<int>&temp=rect[randRecIndx];
        ll a=temp[0],b=temp[1],x=temp[2],y=temp[3];
        int newx=a+(rand()%(x-a+1));
        int newy=b+(rand()%(y-b+1));
        return {newx,newy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
