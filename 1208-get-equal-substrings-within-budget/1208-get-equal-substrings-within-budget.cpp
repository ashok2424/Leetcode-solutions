class Solution {
public:
    int equalSubstring(string s, string t, int max_cost) {
        int i = 0, j = 0,cost = 0,len = 0;
        
        while(j<s.size())
        {
            
            cost += abs(s[j]-t[j]);
            
            while(i<s.size() and cost>max_cost){
                cost-=abs(s[i]-t[i]);
                i++;
            }
            
            len = max(len,j-i+1); j++;
        }
        return len;
    }
};