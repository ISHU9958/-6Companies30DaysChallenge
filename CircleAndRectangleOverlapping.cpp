class Solution {
public:
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                if((x-i)*(x-i)+(y-j)*(y-j) <= r*r){
                    return true;
                }
            }
        }
        return false;
    }
};
