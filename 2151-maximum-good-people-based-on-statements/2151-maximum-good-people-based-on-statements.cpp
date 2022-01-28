class Solution {
public:
   int ans  = 0; vector<vector<int>> a;
    void sub(int n, int i, string &temp,int good){
        if(i==n){
            if(is_valid(temp,a)) ans = max(ans,good);
            return;
        }
        temp.push_back('1');
        sub(n, i+1, temp,good+1);
        temp.pop_back();
        
        temp.push_back('0');  
        sub(n, i+1, temp,good);
        temp.pop_back();
    }
    
    int maximumGood(vector<vector<int>>& nums) {
        string temp = ""; a = nums;
        sub(a.size(), 0,temp,0); 
        return ans;
    }
    bool is_valid(string &temp,vector<vector<int>>& a){
        for(int i = 0;i<temp.size();i++){
            if(temp[i]=='0') continue;//we care only about truth speaker
            for(int j = 0;j<temp.size();j++){
                if(a[i][j]==1 and temp[j]-'0'==0) return false;
                if(a[i][j]==0 and temp[j]-'0'==1) return false;
            }
        }
        return true;
    }
};
