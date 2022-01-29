class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,queue<int>>mp;
        for(int i=0;i<a.size();i++) mp[a[i]].push(i);
        vector<int> ans;
        for(auto &e:b){
            while(mp[e].size()!=0){
                ans.push_back(a[mp[e].front()]); mp[e].pop();
            }
        }
        sort(a.begin(),a.end());
        for(auto &e:a){
            if(mp[e].size()!=0) ans.push_back(e);
        }
        return ans;
    }
};