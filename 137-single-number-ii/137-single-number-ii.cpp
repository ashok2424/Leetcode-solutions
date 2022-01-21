class Solution {
public://refer sumeet malik this is brute
    int singleNumber(vector<int>& nums) {
        //declare variables as long (else p*2 overflows)
        long mask = 1,ans = 0, p = 1;
        
        for(int i=0;i<32;i++){
            int c=0;
            for(auto &e:nums){
                if((e&mask)!=0){ 
                    c++;
                }
            }
            mask = mask<<1;
            if(c%3!=0){
                ans+=p; 
            }
            p*=2;
        }
        return ans;
    }
};

// #Every elem occur K time & one occur X times

// if instead of 3 say for K...then check for c%K and 
// if one elem is repeating X times instead of 1 time
// it will be of form K*y + X . (in prob K = 3, X = 1)