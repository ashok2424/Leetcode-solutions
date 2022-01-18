class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int k) {
        int n = a.size(); vector<int> chairs(n,-1);
        
        //just to restore ind push indices also
        for(int i=0;i<n;i++) a[i].push_back(i);
        
        sort(a.begin(),a.end());
        
        for(auto &v:a){
            int start = v[0] , end = v[1] , ind = v[2]; 
            
            for(int i = 0;i<n;i++){
                if(chairs[i]<=start){
                    if(ind==k) return i;
                    chairs[i] = end; break;
                }
            }            
        }
        return -1;
    }
};

// #O(N*N) ,but optimal is to use priority_queue

// =>First fill all chairs with -1
    
// =>Keep filling chairs[i] = departure time  
//   whenerver the start_time of cur is > chairs[i]

// =>if no freind left till now -1 will take care 
//   present at later index 
 
