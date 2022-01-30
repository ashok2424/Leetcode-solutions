class Solution {
    int dp[202][202];
public:
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m){
        if (i==n-1) return grid[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
		// traverse all elements of next row except same column.
        for (int ind=0;ind<m;ind++){
            if (ind!=j){
                res=min(res,grid[i][j]+solve(grid,i+1,ind,n,m));
            }
        }
        return dp[i][j]=res;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int min_val=INT_MAX;
        memset(dp,-1,sizeof(dp));
		// this loop is for all elements of first row
        for (int i=0;i<m;i++){
            min_val=min(min_val,solve(grid,0,i,n,m));
        }
        return min_val;
    }
};
// class Solution {
// public:
//     int solve(vector<vector<int>> &a,int ind,int prev,vector<vector<int>> &dp){
//         int mini  = 1e9;
//         if(ind==0){
//             for(int i=0;i<a[ind].size();i++){
//                 if(i!=prev) mini = min(a[0][i],mini);
//             }
//             return mini;
//         }
//         if(dp[ind][prev]!=-1) return dp[ind][prev];

//         for(int i=0;i<a[ind].size();i++){
//             if(i!=prev)
//             mini = min(mini,a[ind][i] +  solve(a,ind-1,i,dp));
//         }
//         return dp[ind][prev] = mini;
//     }

//     int minFallingPathSum(vector<vector<int>>& a) {
//         vector<vector<int>>dp(a.size(),vector<int>(a[0].size()+1,-1));
//         return solve(a,a.size()-1,a[0].size(),dp); 
        
// //         int r = a.size(), c = a[0].size(); int dp[r][c+1];
// //           dp[0][0] = max(a[0][1], a[0][2]);
// //           dp[0][1] = max(a[0][0], a[0][2]);
// //           dp[0][2] = max(a[0][0], a[0][1]);
// //           dp[0][3] = max(a[0][0], max(a[0][1], a[0][2]));
// //         // // for(int j = 0;j<a[0].size()+1;j++){
// //         //     int mx = INT_MIN;
// //         //     for(int k = 0;k<a[0].size()+1;k++){
// //         //         if(k!=j) mx = max(mx,a[0][k]);
// //         //     }
// //         //     dp[0][j] = mx;
// //         // }
        
// //         for(int ind = 1;ind<a.size();ind++){
// //             for(int prev = 0;prev<a[0].size()+1;prev++){
// //                 dp[ind][prev] = 1e9;
// //                 for(int i=0;i<a[ind].size();i++){
// //                     if(i!=prev)
// //                     dp[ind][prev] = min(dp[ind][prev],a[ind][i] +  dp[ind-1][i]);
// //                 }
// //             }
// //         }
// //         return dp[r-1][c];                               
//     }
// };