class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        
        string big = s + s;
        
        if(big.find(goal)==string::npos) return false;
        return true;
    }
};
