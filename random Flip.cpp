class Solution {
    int m,n;
    set<pair<int,int>>st;
public:
    Solution(int m, int n) {
        this->m=m;
        this->n=n;
        
    }
    
    vector<int> flip() {
        int randomi=rand() % m;
        int randomj=rand()% n;
        if(st.find({randomi,randomj})==st.end()){
            st.insert({randomi,randomj});
            return {randomi,randomj};
        }
        else return flip();
        return {-1,-1};
    }
    
    void reset() {
        st.clear();
    }
};
