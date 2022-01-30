class Solution {
public:int dp[21][21];
    int solve(int i,int j,vector<int>&a){
        if(i==j) return a[i];
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int op1 = a[i] + min(solve(i+1,j-1,a),solve(i+2,j,a));
        int op2 = a[j] + min(solve(i,j-2,a),solve(i+1,j-1,a));
        
        return dp[i][j] = max(op1,op2);
    }
    bool PredictTheWinner(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(a.begin(),a.end(),0);
        int score = solve(0,a.size()-1,a);
        return score>=(sum/2.0);
    }
};