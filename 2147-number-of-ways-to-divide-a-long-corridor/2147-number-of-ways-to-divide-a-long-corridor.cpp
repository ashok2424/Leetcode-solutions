class Solution {
public://2147. Number of Ways to Divide a Long Corridor
    int numberOfWays(string s) {
        vector<int> v;long seats= 0,ans=1,plants=0;
        
        for(auto &ch:s){
            if(ch=='S'){
                seats++;
                if(seats>2 and seats%2==1){
                    ans = (ans*(plants+1)) % (int)(1e9+7);
                    plants = 0; //set plants = 0 
                }
            }
            if(ch=='P'){
                if(seats>=2 and seats%2==0) plants++;
            }
        }
    
        if(seats==0 or seats%2==1) return 0; // odd seats/no seats
    
        return ans;
    }
};
//   2seats        2seats          2seats
// p  s_s  "p p p" s_s   "p p p p"  s_p_s

// p  s_s  |p|p|p| s_s  |p|p|p|p|  s_s
//         4 ways       5 ways 
      
      
// so by basic pnc 4*5  = 20 ways in total 
//only count plants b/w two pairs of 2 chairs 