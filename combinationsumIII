class Solution {


    // generate function that generates the ans array
    void generate(int i,int k,int target,vector<vector<int>>&ans,vector<int>&temp){
       if(target<0) return ;
       if(target==0 && k==0){
           ans.push_back(temp);
            return;
       }
       if(i>=10) return;
       // i write the main logic
       // i pick up the current element
       temp.push_back(i);
       generate(i+1,k-1,target-i,ans,temp);
       temp.pop_back();

       // i not pick up the current element
       generate(i+1,k,target,ans,temp);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        // first i make the ans array
        vector<vector<int>>ans;
        // no. can be from 1 to 9 so   1<=i<=9;

        // i make the temporary array 
        vector<int>temp;
        generate(1,k,n,ans,temp);
        return ans;
    }
};
