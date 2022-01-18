class Solution {
public:
    int orangesRotting(vector<vector<int>>& m) {
        int r=m.size(); int c=m[0].size(); int timer=0;
        queue<pair<int,int>> q;
        // push all rotten into queue
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(m[i][j]==2){
                    q.push({i,j});
                }
            }
         
        int dx[]={1,-1,0,0}; int dy[]={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
        // 1st finish cuurent time frame (level)
            while(size--){
                auto pr=q.front();q.pop();
                int i=pr.first; int j=pr.second;
                for(int k=0;k<4;k++){
                    int l=i+dx[k];
                    int p=j+dy[k];
                    if(l>=0 and l<r and p>=0 and p<c and m[l][p]==1)
      // push into queue & mark the found fresh as rotten
                    { q.push({l,p});m[l][p]=2; }
                }
            } // level finished
              if(q.size()>0)
                  timer++;
        }
    //check if still fresh are present 
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(m[i][j]==1)
                return -1 ;
            }
        return timer;
    }
};