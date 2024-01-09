class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>cost(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++) cost[i][i]=0;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][via]!=1e9 && cost[via][j]!=1e9){
                        cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
                    }
                }
            }
        }

        int ct=0,cityno=0,citymin=n;
        for(int i=0;i<n;i++){
            int ct=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    ct++;
                }
            }

            if(citymin>=ct){
                citymin=ct;
                cityno=i;
            }
        }
        return cityno;
    }
};
