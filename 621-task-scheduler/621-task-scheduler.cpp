class Solution {
public:
    int leastInterval(vector<char>& a, int lapse) {
        unordered_map<char,int> mp;int max_freq=0;
        for(auto &ch:a){
            mp[ch]++;
            max_freq = max(max_freq,mp[ch]);
        }
        
        int counter = 0;//how many chars share max_freq
        for(auto &[k,val]:mp){
            if(val==max_freq) counter++;
        }
        
        int idles   = (max_freq-1)*lapse;
        int un_idles = max_freq - 1;
        
        int ans = idles + un_idles + counter ;
        
        return max(ans,int(a.size()));
    }
};
//refer deepti talesra 