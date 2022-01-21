class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        long x = 0; //let missing be p,q
        for(auto &e:a) x^=e; //now we have p^q = x;
        
        int rmsb = x&-x; //right most set bit
        
        int p = 0,q = 0;
        
        // cout<<bitset<8>(rmsb);
        
        for(auto &e:a){
            if((rmsb&e)==0){ //bracket are imp (rmsb&e)
                p^=e;
            }else{
                q^=e;
            }
        }
        return {p,q};
    }
};