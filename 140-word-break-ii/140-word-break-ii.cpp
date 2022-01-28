class Solution {
public:unordered_set<string>set;vector<string>ans;
    void solve(string s,string path){
        if(s.size()==0){
            path.erase(path.end()-1);//just erasing that extra " " at last
            ans.push_back(path); return ;
        }
        for(int i=0;i<s.size();i++){
            
            string pref = s.substr(0,i+1);
            string suff = s.substr(i+1);
           
            if(set.count(pref)){
                solve(suff,path + pref + " " );
            }
        }
    }//sumeet malik watch rec tree \U0001f525\U0001f525\U0001f525\U0001f525\U0001f525\U0001f525\U0001f525\U0001f525\U0001f525\U0001f525
    vector<string> wordBreak(string s, vector<string>& dict){
        for(auto &w:dict) set.insert(w);
        solve(s,"");
        return ans;
    }
};
// c __ atsanddog 
// ca __ tsanddog 
// cat __ sanddog //we found cat ..so call for sanddog
// s __ anddog 
// sa __ nddog 
// san __ ddog 
// sand __ dog   //we found sand ..so call for dog
// d __ og 
// do __ g 
// dog __  
// sandd __ og  
// sanddo __ g ......it keeps  going like these
// sanddog __  
// cats __ anddog 
// a __ nddog 
// an __ ddog 
// and __ dog 
// d __ og 
// do __ g 
// dog __  
// andd __ og 
// anddo __ g 
// anddog __  
// catsa __ nddog 
// catsan __ ddog 
// catsand __ dog 
// catsandd __ og 
// catsanddo __ g 
// catsanddog __  
