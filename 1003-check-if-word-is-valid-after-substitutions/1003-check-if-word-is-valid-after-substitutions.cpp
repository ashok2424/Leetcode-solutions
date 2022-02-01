class Solution {
public:
    bool isValid(string s) {
        
        string str = "abc"; int size = str.size();

        while(s.find(str)!=string ::npos){
            
            int ind = s.find(str); 
            s.erase(ind,size);
        }
        return s=="";
    }
};