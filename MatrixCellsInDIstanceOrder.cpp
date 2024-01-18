class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int m=rows,n=cols;
        vector<vector<int>>ans;
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        
        queue<pair<int,int>>q;
        q.push({rCenter,cCenter});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){

            auto front=q.front();
            int x=front.first;
            int y=front.second;
            q.pop();
            ans.push_back({x,y});
            visited[x][y]=1;

            for(int  i=0;i<4;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){
                    
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        return ans;
    }
};
