class FindSumPairs {
public:
    unordered_map<int,int> mp;vector<int> a,b;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto &e:nums2){
            mp[e]++; b.push_back(e);
        }
        for(auto &e:nums1){
            a.push_back(e);
        }
    }
    void add(int index, int val) {
        mp[b[index]]--;
        b[index]+=val;
        mp[b[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto &e:a) ans += mp[tot-e];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */