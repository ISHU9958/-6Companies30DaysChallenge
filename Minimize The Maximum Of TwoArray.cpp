#define ll long long
class Solution {
public:
    int minimizeSet(int d1, int d2, int uc1, int uc2) {
        
        ll i=1,j=1e10,mid,ans=-1;
        while(i<=j){
            mid=i+(j-i)/2;
            
            ll notdivisibleByd1=mid-(mid/d1);
            ll notdivisibleByd2=mid-(mid/d2);
            ll lcm=(d1*(d2*1LL/(__gcd(d1,d2))));
            ll notdivisibleByD1andD2=mid-(mid/d1)-(mid/d2)+(mid/lcm);

            if(notdivisibleByd1>=uc1 && notdivisibleByd2>=uc2 && notdivisibleByd1+notdivisibleByd2-notdivisibleByD1andD2>=(uc1+uc2)){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;

    }
};
