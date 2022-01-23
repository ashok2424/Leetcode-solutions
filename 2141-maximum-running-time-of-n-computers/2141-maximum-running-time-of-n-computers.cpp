class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0 ; for(auto &e:batteries) sum+=e;
        long long l = 0,h =sum;
        long long ans =-1;
        
        while(l<=h){
            long long mid = l + (h-l)/2;
            
            long long run_time = n*mid, c = 0; 
            for(auto &e:batteries){
                c+=min((long long)e,mid);
            } 
            
            if(c>=run_time){
                l = mid+1; ans = mid;
            }
            else{ 
                h = mid -1;
            }
        }
        return ans;
    }
};