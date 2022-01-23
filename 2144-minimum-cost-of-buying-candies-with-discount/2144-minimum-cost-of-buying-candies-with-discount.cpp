class Solution {
public:
    int minimumCost(vector<int>& a) {
        //sort in dec order and skip every 3rd elem
        sort(a.begin(),a.end(),greater<int>());
        
        long long  ans  = 0, c =1;
        for(int i=0;i<a.size();i++){
            if(c%3!=0) ans+=a[i];
            c++;
        }
        
        // for(int i=2;i<a.size();i+=3){
        //     ans-=a[i];
        // }
        return ans;
    }
};