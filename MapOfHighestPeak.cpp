class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>>he(m,vector<int>(n,-1));

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    he[i][j]=0;
                }
            }
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            auto currcell=q.front();
            q.pop();

            int x=currcell.first;
            int y=currcell.second;
            for(int i=0;i<4;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n && he[nx][ny]==-1){
                    q.push({nx,ny});
                    he[nx][ny]=he[x][y]+1;
                }
            }

        }

        return he;

    }
};
