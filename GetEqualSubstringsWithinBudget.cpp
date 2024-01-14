class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n=s.length();

        int i=0,j=0;
        int maxi=0;
        int cost=0;
        while(j<n){
            cost+=abs(t[j]-s[j]);
                while(i<=j && cost>maxCost){

                    cost-=abs(t[i]-s[i]);
                    i++;
                }
                maxi=max(maxi,j-i+1);
                j++;

        }
        return maxi;
    }
};
