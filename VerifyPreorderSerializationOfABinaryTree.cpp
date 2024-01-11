class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> v;
 
        stringstream ss(preorder);
    
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

        stack<string>st;
        for(auto &it:v){
            if(it!="#") st.push(it);
            else if(it=="#"){
                while(st.size()>=2 && st.top()=="#"){
                    st.pop();
                    st.pop();
                }
                if(st.size()==1 && st.top()=="#") return false;
                
                st.push("#");
            }
        }
        return st.size()==1 && st.top()=="#";
    }
};
