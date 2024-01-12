class Solution {

    void dfs(auto &visited,auto &board,int i,int j,int &m,int &n){
        visited[i][j]=1;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        for(int l=0;l<4;l++){
            int nr=i+dr[l];
            int nc=j+dc[l];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && board[nr][nc]=='X'){
                dfs(visited,board,nr,nc,m,n);
            }
        }

    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));

        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' && !visited[i][j]){
                    dfs(visited,board,i,j,m,n);
                    ct++;
                }
            }
        }

        return ct;
    }
};
