class Solution {

    bool check(string &s,string &word){

        int m=s.length(),n=word.length();

        int i=0,j=0;
        while(i<m && j<n){
            if(s[i]==word[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(j>=n) return true;
        return false;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        int maxlen=0;
        string ans="";
        for(auto &it:dictionary){
            if(check(s,it)){
                if(it.length()>maxlen){
                    ans=it;
                    maxlen=it.length();
                }
                else if(it.length()==maxlen){
                    if(ans>it){
                        ans=it;
                    }
                }
            }
        }

        return ans;
    }
};
