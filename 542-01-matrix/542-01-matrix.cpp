class Solution {
public: //542. 01 Matrix (the distance of the nearest 0 for each cell.)
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int r = a.size();int c = a[0].size(); queue<pair<int,int>> q; 
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                
                if(a[i][j]==0)  q.push({i,j});//push '0' cells to queue
                
                else a[i][j] = INT_MAX; //turn 1 cells to INT_MAX
            }
        }
        
        //simple bfs starting from all 0 cells
        while(q.size()){
            auto [i,j] = q.front(); q.pop(); //avoid &[i,j] gets error
            
            int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
            
            for(int k=0;k<4;k++){
                
                int ni = i + d[k][0];
                int nj = j + d[k][1];
                
                if(ni>=0 and ni<r and nj>=0 and nj<c ){
                    if(a[ni][nj] > a[i][j]+1){
                        a[ni][nj] = a[i][j] + 1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return a;
    }
};