class Solution {
public://fixed size slid wind prob
    vector<string> findRepeatedDnaSequences(string a) {
        string s=""; int i=0,j=0; map<string,int> mp;
        while(j<a.size()){
            s+=a[j];
            if(j-i+1==10){
                mp[s]++;
                s.erase(s.begin()+0);
                i++;
            }
            j++;
        }
        vector<string>ans;
        for(auto pr:mp){
            if(mp[pr.first]>1)
              ans.push_back(pr.first);
        }
        return ans;
    }
};