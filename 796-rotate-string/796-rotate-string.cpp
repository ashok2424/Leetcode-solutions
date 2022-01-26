class Solution {
public:
    string rotate(string s,int k){
        reverse(s.begin(),s.begin()+k);
        reverse(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
    bool rotateString(string s, string goal) {
        for(int i=1;i<=s.size();i++){
            string temp = s;
            if(rotate(temp,i)==goal) return true;
        }
        return false;
    }
};
