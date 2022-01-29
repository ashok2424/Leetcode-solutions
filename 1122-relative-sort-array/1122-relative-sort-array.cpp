class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        unordered_map<int,int>mp; vector<int> ans;
        
        for(int i=0;i<a.size();i++) mp[a[i]]++;
        
        for(auto &e:b){
            while(mp[e]!=0){
                ans.push_back(e); mp[e]--;
            }
        }
        
        //for those elems not in b arr
        sort(a.begin(),a.end());
        for(auto &e:a){
            if(mp[e]!=0) ans.push_back(e);
        }
        return ans;
    }
};

//for those elems not in b arr u can take them into 
//seperate arr and sort them instead sorting whole "a" arr