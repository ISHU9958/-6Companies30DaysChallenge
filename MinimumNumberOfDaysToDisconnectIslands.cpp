class Solution {
    vector<vector<bool>>visited;
    int  m,n;

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(int x,int y,auto &grid){


        visited[x][y]=1;
      

    
        for(int i=0;i<4;i++){
            int nx=x+dr[i];
            int ny=y+dc[i];

            
            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
      
                if(!visited[nx][ny]){

                    dfs(nx,ny,grid);
                    
                }
            }
        }

        
    }

    int countLands(auto &grid){

        int count=0;
        visited.clear();
        visited.resize(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        
        m=grid.size(),n=grid[0].size();
 
        int landct=countLands(grid);
        if(landct>1 || landct==0) return 0;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int landct=countLands(grid);
                    if(landct>1 || landct==0) return 1;

                    grid[i][j]=1;
                }
                
            }
        }

        return 2;
    }
};
