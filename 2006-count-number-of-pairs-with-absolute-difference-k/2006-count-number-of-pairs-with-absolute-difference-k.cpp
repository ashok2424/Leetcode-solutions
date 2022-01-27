class Solution {
public:
    int countKDifference(vector<int>& a, int k) {
        unordered_map<int,int> mp;int ans = 0;
        for(auto &e:a){
            int x = (e-k);
            int y = k +  e;
            ans += mp[x] +  mp[y];
            mp[e]++;
        }
        return  ans;
    }
};
// [7,7,8,3,1,2,7,2,9,5]
//          2 1 1 1 1