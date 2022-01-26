class Solution {
public:
    int numberOfWays(string s) {
        vector<int> v;long seats= 0,ans=1,plants=0;
        for(auto &ch:s){
            if(ch=='S'){
                seats++;
                if(seats>2 and seats%2==1){
                    v.push_back(plants+1); plants = 0;
                }
            }
            if(ch=='P'){
                if(seats>=2 and seats%2==0) plants++;
            }
        }
        if(seats==0 or seats%2==1) return 0; //odd seats 
        
        for(auto &e:v){
            // cout<<e<<" ";
            ans = (ans*e)%(int)(1e9+7);
        }
        return ans;
    }
};

// p s s "p p p" s s "p p p"  s s