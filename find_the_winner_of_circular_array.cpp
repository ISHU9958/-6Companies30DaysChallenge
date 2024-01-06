// approach 1

class Solution {
    int f(int n,int k){
        if(n==1) return 0;
        return (f(n-1,k)+k)%n;
    }
public:
    int findTheWinner(int n, int k) {
        return f(n,k)+1;
    }
};


// approach 2

class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int>dq;
        for(int i=1;i<=n;i++){
            dq.push_back(i);
        }

        while(dq.size()!=1){
            for(int i=1;i<=k-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
        return dq.front();
    }
};
