class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        vector<int> ans;stack<int>s;
        
        for(int i = a.size()-1;i>=0;i--){
            
            while(s.size() and a[s.top()]<=a[i]){
                s.pop();
            }
            
            if(s.size()==0) ans.push_back(0);
            else ans.push_back(s.top()-i);
            
            s.push(i);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};