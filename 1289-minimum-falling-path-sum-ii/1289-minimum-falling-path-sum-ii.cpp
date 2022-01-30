class Solution {
public:int dp[202][202];
    int minFallingPathSum(vector<vector<int>>& a) {
        int ans = INT_MAX;memset(dp,-1,sizeof(dp));
        //know where to start in 1st row
        for(int j = 0;j<a[0].size();j++){
            ans = min(ans,solve(a,0,j));
        }
        return ans;
    }
    int solve(vector<vector<int>>& a,int i,int j){
        if(i==a.size()-1) return a[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int col = 0;col<a[0].size();col++){
            if(col!=j){
                ans = min(ans,a[i][j] + solve(a,i+1,col));
            }
        }
        return dp[i][j] =  ans;
    }
};