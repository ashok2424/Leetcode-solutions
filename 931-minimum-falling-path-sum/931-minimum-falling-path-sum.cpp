class Solution {
public: int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& a) {
    for(int i=0;i<101;i++) for(int j=0;j<101;j++) dp[i][j]=INT_MIN;
         int ans=INT_MAX;
         for(int j=0;j<a[0].size();j++){
             ans = min(ans,solve(0,j,a));
         }
        return ans;
    }
    int solve(int r,int c,vector<vector<int>>& a){
         
        if(c<0 or c>=a[0].size()) return 1e9;
        if(r==a.size()-1) return a[r][c];  
        
        if(dp[r][c]!=INT_MIN) return dp[r][c];
        
        int p = a[r][c] + solve(r+1,c,a);
        int q = a[r][c] + solve(r+1,c+1,a);
        int l = a[r][c] + solve(r+1,c-1,a);
         
        return dp[r][c]= min({p,q,l});
    }
};