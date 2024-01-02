class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long val1=0;
        long long val2=0;
        long long sum1=0;
        long long sqsum1=0;
        long long sqsum2=(1LL*(n)*(n+1)*(2*n+1))/6;
        long long  sum2=(1LL*n*(n+1))/2;
        for(int i=0;i<n;i++){
            sum1+=arr[i];
            sqsum1+=((long long)arr[i]* (long long)arr[i]);
        }
        val1=sum1-sum2;
        val2=sqsum1-sqsum2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=x-val1;
        return {(int)x,(int)y};
    }
};
