class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        vector<int> ind_arr; int n = a.size();
        unordered_map<int,queue<int>> mp;
        for(int i=0;i<n;i++) mp[a[i]].push(i);
        
        sort(begin(a),end(a));
        for(auto &e:a){
            ind_arr.push_back(mp[e].front()); mp[e].pop();
        }
        
        int mn = n,width = 0;
        for(auto &ind:ind_arr){
            mn = min(mn,ind);
            width = max(width,ind-mn);
        }
        return width;
    }
};
//  0 1 2 3 4 5
// [6,0,8,2,1,5]

// ind_arr: 1 4 3 5 0 2
//         [0,1,2,5,6,8]

//  0 1 2 3 4 5 6 7 8 9
// [9,8,1,0,1,9,4,0,4,1]


// [0,0,1,1,1,4,4,8,9,9 ]