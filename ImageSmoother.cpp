class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();

        vector<vector<int>>ans(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){


                long long sum=0;
                int ct=0;

                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){

                        int nr=i+k;
                        int nc=j+l;

                        if(nr<0 || nc<0 || nr>=m ||  nc>=n) continue;

                        sum+=arr[nr][nc];
                        ct++;
                    }
                }

                ans[i][j]=sum/ct;
            }
        }

        return ans;
    }
};
