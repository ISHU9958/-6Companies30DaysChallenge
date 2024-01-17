class Solution {

    int dp[4][51][51][51]={0};
    int f(int prev,int x,int y,int z){
        if(dp[prev+1][x][y][z]!=0) return dp[prev+1][x][y][z];
        int maxi=0;
        if(prev==-1){
            if(x>0) maxi=max(maxi,1+f(0,x-1,y,z));
            if(y>0) maxi=max(maxi,1+f(1,x,y-1,z));
            if(z>0) maxi=max(maxi,1+f(2,x,y,z-1));
        }
        else if(prev==0 && y>0){  // last time x take and call to only y
            maxi=max(maxi,1+f(1,x,y-1,z));
        }

        else if(prev==1){

            if(x>0){
                maxi=max(maxi,1+f(0,x-1,y,z));
            }
            if(z>0){
                maxi=max(maxi,1+f(2,x,y,z-1));
            }

        }

        else if(prev==2){

            if(x>0){
                maxi=max(maxi,1+f(0,x-1,y,z));
            }
            if(z>0){
                maxi=max(maxi,1+f(2,x,y,z-1));
            }
        }

        return dp[prev+1][x][y][z]= maxi;
    }
public:
    int longestString(int x, int y, int z) {
        

        return f(-1,x,y,z)*2;
    }
};
