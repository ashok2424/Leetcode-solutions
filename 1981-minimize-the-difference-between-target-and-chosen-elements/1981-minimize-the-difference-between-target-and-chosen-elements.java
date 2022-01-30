class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        int m=mat.length,n=mat[0].length;
        Integer[][] dp=new Integer[m+1][10000];
        return rec(mat,0,m,n,target,0,dp);
    }
    int rec(int[][] mat,int idx,int m,int n,int target,int sum,Integer dp[][])
    {
        if(idx==m){
            return Math.abs(target-sum);
        }
        if(dp[idx][sum]!=null) return dp[idx][sum];
        
        int min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            min=Math.min(rec(mat,idx+1,m,n,target,mat[idx][i]+sum,dp),min);
        }
        return dp[idx][sum]=min;
    }
}