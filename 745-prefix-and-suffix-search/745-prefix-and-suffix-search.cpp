class WordFilter {
public: unordered_map<string,int>mp;
    //TC : 15,000 * 100 = 15,00,000 1.5 * 10^6 ;
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
//if we assign mp[key] = ind,then for returning -1  write one more if below
    
    int f(string pref, string suf) {
        string key = pref + "|" + suf;
        return mp[key]-1;
    }
};
/*
Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.
*/
