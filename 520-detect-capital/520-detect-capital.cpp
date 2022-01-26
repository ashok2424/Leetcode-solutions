class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), c = 0; 
        for(auto ch:word){
            char t = ch;
            ch = tolower(ch);
            if(ch==t) c++;
        }
        if((c==n ) or (c==n-1 and word[0]==toupper(word[0]))) return true;
        int d=0;
        for(auto ch:word){
            char t = ch;
            ch = toupper(ch);
            if(ch==t) d++;
        }
        if(d==n) return true;
        return false;
    }
};