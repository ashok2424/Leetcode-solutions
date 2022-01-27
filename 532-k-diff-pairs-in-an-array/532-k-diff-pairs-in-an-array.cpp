class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        unordered_map<int,int> mp; int ans = 0;
        for(auto &e:a) mp[e]++;
        
        for(auto &[e,v]:mp){
            if(k==0 and v>1) ans++;
            else if(k!=0){
                if(mp.count(e+k)) ans++;
            }
        }
        return ans;
    }
};