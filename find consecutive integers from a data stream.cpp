class DataStream {
    int freq=0;
    int value;
    int k;
    int prev=-1;
    int present;
public:
    DataStream(int value, int k) {
        this->value=value;
        this->k=k;
    }
    
    bool consec(int num) {
        present=num;
        if(present==value && present!=prev){
            freq=1;
            prev=present;
            if(freq>=k) return true;
            return false;
        }
        else if(present==value && present==prev){
            freq++;
            prev=present;
            if(freq>=k) return true;
            return false;
        }
        freq=0;
        prev=present;
        return false;
    }
};
