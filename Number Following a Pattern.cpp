class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n=s.length();
        string ans;
        ans.push_back('1');
        int curr=1;
        int i=0;
        while(i<n){
            if(s[i]=='I'){
                curr++;
                ans.push_back(curr+'0');
                i++;
            }
            else{
                int j=i;
                while(j<n && s[j]=='D') j++;
                
                int NoD=j-i;
                curr=curr+NoD;
                ans[i]=curr+'0';
                int count=curr;
                while(i<n && NoD--){
                    count--;
                    ans.push_back('0'+count);
                    i++;
                }
            }
        }
        return ans;
    }
};
