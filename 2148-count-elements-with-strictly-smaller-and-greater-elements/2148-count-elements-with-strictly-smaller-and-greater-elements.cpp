class Solution {
public:
    int countElements(vector<int>& a) {
        int mini = *min_element(a.begin(),a.end());
        int maxi = *max_element(a.begin(),a.end());
        
        int ans =0;
        for(auto &e:a){
            if(e>mini and e<maxi) ans++;
        }
        return ans;
    }
};