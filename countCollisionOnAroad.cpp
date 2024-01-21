class Solution {

    bool ispossibleToCollide(char &top , char &ch,int  &coli){
            if(top=='R' && ch=='L'){
                coli+=2;
                return true;
            }
            else if((top=='R' && ch=='S') || (top=='S' && ch=='L')){
                coli++;
                return true;
            }

            return false;
    }
public:
    int countCollisions(string directions) {
        stack<char>st;

        int coli=0;
        for(auto &ch:directions){

            if(st.empty()){
                st.push(ch);
                continue;
            }

            char tempch=ch;
            while(!st.empty() && ispossibleToCollide(st.top(),tempch,coli)){
                st.pop();
                tempch='S';
            }
            st.push(tempch);
        }

       
        return coli;
    }
};
