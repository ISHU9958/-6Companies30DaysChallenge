class Solution {
    
    
    bool check(auto&arr,int i,int k){
        

        int l=0,r=arr.size()-1;
        
        while(l<=r){
            
            int mid=(l+r)>>1;
            if(arr[mid]==i || (i<arr[mid] && arr[mid]<=k+i)) return true;
            else if(arr[mid]<i){
                l=mid+1;
            }
            else r=mid-1;
            
        }
        
        l=0,r=arr.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(arr[mid]==i || (i-k<=arr[mid] && arr[mid]<i)) return true;
            else if(arr[mid]<i-k){
                l=mid+1;
            }
            else r=mid-1;
        }
        
        return false;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        int alen=a.size();
        int blen=b.size();
        int slen=s.size();
        v(int) jarray;
        
        for(int j=0;j<=slen-blen;j++){
            if(s.substr(j,blen)==b){
                jarray.push_back(j);
            }
        }
        
        v(int) ans;
        // unordered_set<int>st;
        for(int i=0;i<=slen-alen;i++){
            if(s.substr(i,alen)==a){
           
                int flag=check(jarray,i,k);
                if(flag){
                    ans.push_back(i);
                }
            }
        }
    
        return ans;
        
    }
};
