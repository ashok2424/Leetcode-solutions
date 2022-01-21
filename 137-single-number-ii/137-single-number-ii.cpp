class Solution {
public:
    int singleNumber(vector<int>& nums) {
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
// 10010