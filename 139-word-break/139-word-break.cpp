class Solution {
public:unordered_set<string>set; bool ans=0;unordered_map<string ,bool>mp;
    
    bool solve(string s){
        if(s==""){
            return mp[s]=true;
        }
        if(mp.count(s)) return mp[s];//dp
        string word="";
        for(int i=0;i<s.size();i++){
            word+=s[i]; 
            if(set.count(word) and solve(s.substr(i+1))){ //cout<<word<<" "<<i<<endl;
                 return mp[s]=true;
            }
        }
        return mp[s]=false;
    }

    bool wordBreak(string s, vector<string>& dict) {
        for(auto &w:dict) set.insert(w);
         return solve(s);
    }
};