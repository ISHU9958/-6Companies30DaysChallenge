class Solution {
void f(int i,int &n,string &temp,vector<string>&ans,unordered_map<int,string>&mp,string &digits){
    if(i>=n){
        ans.push_back(temp);
        return;
    }

    int ind=digits[i]-'0';
    string dial=mp[ind];

    for(int j=0;j<dial.length();j++){
        temp.push_back(dial[j]);
        f(i+1,n,temp,ans,mp,digits);
        temp.pop_back();
    }

}
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

        int n=digits.size();
        vector<string>ans;
        if(n==0)return ans;
        string temp;
        f(0,n,temp,ans,mp,digits);
        return ans;
    }
};
