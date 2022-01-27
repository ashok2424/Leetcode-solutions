class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int max_from_front = 0 , n  = a.size();
        
        for(int i = 0;i<n-2;i++){
            
            max_from_front = max(max_from_front,a[i]);
            
            if(max_from_front > a[i+2]) return false;
        }
        return true;
    }
};


// int cmax = 0, n = A.size();
//         for (int i = 0; i < n - 2; ++i) {
//             cmax = max(cmax, A[i]);
//             if (cmax > A[i + 2]) return false;
//         }
//         return true;



