class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int max_from_front = 0 ; int  n  = a.size();
        
        for(int i = 0;i<n-2;i++){
            
            max_from_front = max(max_from_front,a[i]);
            
            if(max_from_front > a[i+2]) return false;
            
        }
        return true;
    }
};
// The problem asks us to find whether the no. of glob_inv == to loc_inv ??
// And we know all loc_inv are glob. Why? Cuz loc_inv are basically gobal with a dist as 1 b/w them.
    
// So if we can find at least one glob_inv which is not local our job is done & we return false
// And since we are maintaining the maximum value all the cases will be covered in it.


// for (int i = 0; i < A.length; i++) {
//     if (Math.abs(i - A[i]) > 1)
//         return false;
// }

// Elements to the right of A[i] must be bigger than A[i] except for A[i + 1].

// Assuming N=4, i = 1 

// A = [0,1, 2, 3] satisfy

// // A[i] can switch with A[i + 1]
// A = [0, 2, 1, 3] satisfy

// // A[i] can switch with A[i - 1]
// A = [1, 0, 2, 3] satisfy

// but A = [0, 3, 2, 1] and A = [0, 3, 1, 2] wouldn't satisfy
// So |i - A[i]| <= 1 is an invariant.




// dont forget to type cast
// for(int i = 0;i<(int)a.size()-2;i++) 



