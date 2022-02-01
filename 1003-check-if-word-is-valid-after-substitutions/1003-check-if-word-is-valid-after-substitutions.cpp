class Solution {
public:
    bool isValid(string s) {
        string str = "abc";
        while(s.find(str)!=string ::npos){
            s.erase(s.find(str),str.size());
        }
        return s=="";
    }
};