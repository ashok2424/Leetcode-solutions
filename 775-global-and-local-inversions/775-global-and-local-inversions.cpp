class Solution {
public:
    int merge(vector<int> & temp,vector<int> &a,int left,int mid,int right){
        int inv = 0 , i = left , j = mid ,k = left;
        while(i<=mid-1 and j<=right){
            if(a[i]<=a[j]){
                temp[k++] = a[i]; i++;
            }else{
                temp[k++] = a[j]; j++; inv += mid-i; 
            }
        }
        while(i<=mid-1) {temp[k++] = a[i]; i++;}
        while(j<=right) {temp[k++] = a[j]; j++;}
        
        for(int i = left;i<=right;i++) a[i] = temp[i];
        return inv; //keep all sorted elems in temp back to a from left to right
    }
    
    long count_inv(vector<int> &temp,vector<int> &a,int left,int right){
        long inv = 0;
        if(left<right){
            int mid = (left+right)/2;
            
            inv += count_inv(temp,a,left,mid);
            inv += count_inv(temp,a,mid+1,right);
            
            inv += merge(temp,a,left,mid+1,right);
        }
        return inv;
    }
    
    bool isIdealPermutation(vector<int>& a) {
        int glob = 0,loc=0,mn = INT_MAX;vector<int>aa(a),temp(a.size());
        //glob  = count inv in array using merge sort
        glob = count_inv(temp,a,0,a.size()-1);//always take temp arr to merge
        
        for(int i=0;i<aa.size()-1;i++) if(aa[i]>aa[i+1]) loc++;
        return glob==loc;
    }
};

          