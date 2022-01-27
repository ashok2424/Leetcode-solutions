class Solution {
public:
    int merge(vector<int> & temp,vector<int> &a,int left,int mid,int right){
        int inv = 0;
        int i = left , j = mid ,k = left;
        while(i<=mid-1 and j<=right){
            if(a[i]<=a[j]){
                temp[k++] = a[i]; i++;
            }else{
                inv += mid-i;
                temp[k++] = a[j]; j++;
            }
        }
        while(i<=mid-1) {temp[k++] = a[i]; i++;}
        while(j<=right) {temp[k++] = a[j]; j++;}
        
        for(int i = left;i<=right;i++){
            a[i] = temp[i];
        }
        return inv;
    }
    long get_inv(vector<int> &temp,vector<int> &a,int left,int right){
        long inv = 0;
        if(left<right){
            int mid = (left+right)/2;
            
            inv += get_inv(temp,a,left,mid);
            inv += get_inv(temp,a,mid+1,right);
            // cout<<mid<<endl;
            inv += merge(temp,a,left,mid+1,right);
            // cout<<mid<<endl;
        }
        return inv;
    }
    bool isIdealPermutation(vector<int>& a) {
        int glob = 0,loc=0,mn = INT_MAX;vector<int>aa(a);
        vector<int>temp(a.size());
        glob = get_inv(temp,a,0,a.size()-1);
        for(int i=0;i<aa.size()-1;i++){
            if(aa[i]>aa[i+1]) loc++;
        }
        // cout<<glob<<" "<<loc<<endl;
        return glob==loc;
    }
};

// [2,3,4,0,1,5]
//  2 2 2 0 0 0   
          