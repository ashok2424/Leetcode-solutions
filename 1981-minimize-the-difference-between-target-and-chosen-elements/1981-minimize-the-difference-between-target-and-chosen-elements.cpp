class Solution {
public: int dp[71][56000];
    vector<vector<int>> a; int diff = INT_MAX ;
    
    int solve(int i,int sum,int k){
        if(i==a.size()){
            return  abs(sum-k);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int ans = INT_MAX;
        for(int j = 0;j<a[i].size();j++){
            ans = min(ans,solve(i+1,sum + a[i][j],k));
        }
        return dp[i][sum] =  ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int k) {
        memset(dp,-1,sizeof(dp));
        a = mat; return solve(0,0,k);
    }
};