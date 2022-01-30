class Solution {
public: int dp[101][101];
    int minFallingPathSum(vector<vector<int>>& a) {
    for(int i=0;i<101;i++) for(int j=0;j<101;j++) dp[i][j]=INT_MIN;
        
         int ans=solve(0,0,a);
         for(int i=1;i<a[0].size();i++){
             int temp = solve(0,i,a);
             ans = min(ans,temp);
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