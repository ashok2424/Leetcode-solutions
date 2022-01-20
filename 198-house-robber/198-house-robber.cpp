class Solution {
public:
    int rob(vector<int>& a) {
         int n;
    int b[105];
        n=a.size();
        fill(b,b+100,0);
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1||i==n-2)b[i]=a[i];
            else if(i==n-3) b[i]=a[i]+b[i+2];
            else
            {
                b[i]=a[i]+max(b[i+2],b[i+3]);
            }
        }
        return max(b[0],b[1]);
    }
};