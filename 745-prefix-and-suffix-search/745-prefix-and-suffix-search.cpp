class WordFilter {
public: unordered_map<string,int>mp;
    
    WordFilter(vector<string>& a) {
        for(int ind= 0;ind<a.size();ind++){
           string s = a[ind] , pref = "",suff = "";
            
           for(int i=0;i<s.size();i++){
               pref = s.substr(0,i+1); // a,ap,app,appl,apple
               
               for(int j = 0;j<s.size();j++){
                   suff = s.substr(j); // apple ,pple,ple,le,e
                   string key = pref + "|" + suff;
                   mp[key] = ind+1;
               }
           }
        }
    }
    
    int f(string pref, string suf) {
        string key = pref + "|" + suf;
        return mp[key]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */